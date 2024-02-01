#include "addi.h"

void* addi_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    if(tokens.size()!=3){
        throw invalid_argument("invalid arguments in addi");
    }

    if(!regs.check(tokens[0])){
        throw invalid_argument("register " + tokens[0] + " does not exist");
    }

    if(!regs.check(tokens[1])){
        throw invalid_argument("register " + tokens[1] + " does not exist");
    }
    
    addi* st = new addi;
    st->store_rg=tokens[0];
    st->first_rg=tokens[1];

    if(is_number(tokens[2])){
        st->label = "";
        st->literal = to_number(tokens[2]);
    }else{
        st->label=tokens[2];
        unconfirmed_labels.insert(tokens[2]);
    }

    return st;
}


void addi_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    addi info = *(addi*)st;
    int f_reg = regs.load_word(info.first_rg);
    if(info.label==""){
        f_reg+=info.literal;
    }else{
        f_reg+=labels[info.label];
    }
    regs.store_word(info.store_rg,f_reg);
    regs.next(-1);
}
