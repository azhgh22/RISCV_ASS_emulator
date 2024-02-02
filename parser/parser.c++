#include "parser.h"

Parser::Parser(string file_path,Memory* mem,cpu* regs){
    this->mem=mem;
    this->regs=regs;
    init_cmds();
    ifstream f(file_path);
    string line;

    while(getline(f,line)){
        parse_line(remove_comments(ltrim(line)));
    }
    
    f.close();

    analise_labels();
    
}

void Parser::analise_labels(){
    for(string l : unconfirmed_labels){
        if(labels.find(l)==labels.end()){
            throw invalid_argument("label \""+ l +"\" does not exist");
        }   
    }
}


Parser::~Parser(){
    //free all mallocs
    for(int i=0;i<cmd_queue.size();i++){
        Command c = cmd_queue[i];
        delete c.cmd_ptr;
    }
}


void Parser::parse_line(string line){
    // parse line and add appropriate command to vector
    vector<string> tokens;
    tokenise(tokens,line);

    if(isLabel(tokens)){
        string label_name = tokens[0].substr(0,tokens[0].size()-1);
        labels[label_name]=cmd_queue.size();
        tokens.erase(tokens.begin());
    }

    if(tokens.size()==0){
        return;
    }

    string cmd_name = tokens[0];
    tokens.erase(tokens.begin());
    if(cmd_inits.find(cmd_name)!=cmd_inits.end()){
        // create command and put it into cmd_queue;
        Command cmd;
        cmd.cmd_ptr = cmd_inits[cmd_name](tokens,line,*regs,unconfirmed_labels);
        cmd.type=to_lower(cmd_name);
        cmd_queue.push_back(cmd);
    }

}


void Parser::init_cmds(){
    put_inits();
    put_runs();
}

void Parser::put_inits(){
    cmd_inits[to_lower(string("add"))] = add_init;
}

void Parser::put_runs(){
    cmd_runs[to_lower(string("add"))]= add_run;
}

void Parser::print(){
    for(pair<string,unsigned int>  l : labels){
        cout<<l.first<<"  "<<l.second<<endl;
    }
    cout<<"#########"<<endl;
    for(int i=0;i<cmd_queue.size();i++){
        cout<<cmd_queue[i].type<<endl;
    }
}


void Parser::run(int cmd_idx){
    Command cmd = cmd_queue[cmd_idx];
    cmd_runs[cmd.type](cmd.cmd_ptr,*regs,*mem,labels);
}


unsigned int Parser::count_cmds(){
    return cmd_queue.size();
}