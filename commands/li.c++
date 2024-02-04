#include "li.h"

void* li_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    if(tokens.size()!=2){
        throw invalid_argument("invalid arguments in li");
    }

    if(!regs.check(tokens[0])){
        throw invalid_argument("register " + tokens[0] + " does not exist");
    }

    li* st = new li;
    st->store_rg=tokens[0];
    if(is_number(tokens[1])){
        st->literal=to_number(tokens[1]);
        st->label="";
    }else if(is_char(tokens[1])){
        st->literal=(int)tokens[1][1];
        st->label="";
    }
    else{
        st->label = tokens[1];
        unconfirmed_labels.insert(tokens[1]);
    }
    return st;
}

void li_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    li info = *(li*)st;
    if(info.label==""){
        regs.store_word(info.store_rg,info.literal);
    }else{
        regs.store_word(info.store_rg,labels[info.label]);
    }
    regs.next(-1);
}