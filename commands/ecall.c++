#include "ecall.h"

void* ecall_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    if(tokens.size()!=0) throw invalid_argument("invalid arguments in ecall");
    return nullptr;
}

void ecall_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    int type = regs.load_word("x10");
    int val = regs.load_word("x11");
    if(type==1){
        cout<<val;
        regs.next(-1);
    }else if(type==10){
        regs.next(labels["1"]);
    }else if(type==11){
        cout<<(char)val;
        regs.next(-1);
    }
}