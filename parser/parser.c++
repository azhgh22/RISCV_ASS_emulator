#include "parser.h"

Parser::Parser(string file_path,Memory* mem,cpu* regs){
    this->mem=mem;
    this->regs=regs;
    init_genral_strings();
    init_cmds();
    ifstream f(file_path);
    string line;

    while(getline(f,line)){
        parse_line(remove_comments(ltrim(line)));
    }
    
    f.close();

    analise_labels();
    labels["1"]=cmd_queue.size();
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
        if(c.cmd_ptr!=nullptr){
            delete c.cmd_ptr;
        }
    }
}

void Parser::init_genral_strings(){
    general_strings.insert(".text");
    general_strings.insert(".global");
}

void Parser::parse_line(string line){
    // parse line and add appropriate command to vector
    vector<string> tokens;
    tokenise(tokens,line);

    if(tokens.size()==0){
        return;
    }

    if(general_strings.find(tokens[0])!=general_strings.end()){
        tokens.erase(tokens.begin());
    }

    if(tokens.size()==0){
        return;
    }

    if(isLabel(tokens)){
        string label_name = tokens[0].substr(0,tokens[0].size()-1);
        labels[label_name]=cmd_queue.size();
        tokens.erase(tokens.begin());
    }

    if(tokens.size()==0){
        return;
    }

    string cmd_name = to_lower(tokens[0]);
    tokens.erase(tokens.begin());
    if(cmd_inits.find(cmd_name)!=cmd_inits.end()){
        // create command and put it into cmd_queue;
        Command cmd;
        cmd.cmd_ptr = cmd_inits[cmd_name](tokens,line,*regs,unconfirmed_labels);
        cmd.type=cmd_name;
        cmd_queue.push_back(cmd);
    }else{
        throw invalid_argument(cmd_name+" instuction does not exist");
    }

}


void Parser::init_cmds(){
    put_inits();
    put_runs();
}

void Parser::put_inits(){
    cmd_inits["add"] = add_init;
    cmd_inits["addi"] = addi_init;
    cmd_inits["beq"] = beq_init;
    cmd_inits["bge"] = bge_init;
    cmd_inits["bgt"] = bgt_init;
    cmd_inits["ble"] = ble_init;
    cmd_inits["blt"] = blt_init;
    cmd_inits["bne"] = bne_init;
    cmd_inits["call"] = call_init;
    cmd_inits["div"] = div_init;
    cmd_inits["j"] = j_init;
    cmd_inits["jal"] = jal_init;
    cmd_inits["jalr"] = jalr_init;
    cmd_inits["jr"] = jr_init;
    cmd_inits["lb"] = lb_init;
    cmd_inits["lh"] = lh_init;
    cmd_inits["li"] = li_init;
    cmd_inits["lw"] = lw_init;
    cmd_inits["mul"] = mul_init;
    cmd_inits["mv"] = mv_init;
    cmd_inits["ret"] = ret_init;
    cmd_inits["sb"] = sb_init;
    cmd_inits["sh"] = sh_init;
    cmd_inits["sub"] = sub_init;
    cmd_inits["sw"] = sw_init;
    cmd_inits["ecall"] = ecall_init;
    cmd_inits["print"] = print_init;
}

void Parser::put_runs(){
    cmd_runs["add"] = add_run;
    cmd_runs["addi"] = addi_run;
    cmd_runs["beq"] = beq_run;
    cmd_runs["bge"] = bge_run;
    cmd_runs["bgt"] = bgt_run;
    cmd_runs["ble"] = ble_run;
    cmd_runs["blt"] = blt_run;
    cmd_runs["bne"] = bne_run;
    cmd_runs["call"] = call_run;
    cmd_runs["div"] = div_run;
    cmd_runs["j"] = j_run;
    cmd_runs["jal"] = jal_run;
    cmd_runs["jalr"] = jalr_run;
    cmd_runs["jr"] = jr_run;
    cmd_runs["lb"] = lb_run;
    cmd_runs["lh"] = lh_run;
    cmd_runs["li"] = li_run;
    cmd_runs["lw"] = lw_run;
    cmd_runs["mul"] = mul_run;
    cmd_runs["mv"] = mv_run;
    cmd_runs["ret"] = ret_run;
    cmd_runs["sb"] = sb_run;
    cmd_runs["sh"] = sh_run;
    cmd_runs["sub"] = sub_run;
    cmd_runs["sw"] = sw_run;
    cmd_runs["ecall"] = ecall_run;
    cmd_runs["print"] = print_run;
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