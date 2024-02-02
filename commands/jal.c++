#include "jal.h"

void* jal_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    if(tokens.size()!=2) __throw_invalid_argument("invalid arguments in jal");
    if(!regs.check(tokens[0])) __throw_invalid_argument("invalid arguments in call");
    unconfirmed_labels.insert(tokens[1]);
    jal* st = new jal;
    st->label=tokens[1];
    st->rg=tokens[0];
    return st;
}

void jal_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    jal info = *(jal*)st;
    int pc = regs.load_word("pc");
    pc++;
    regs.store_word(info.rg,pc);
    regs.next(labels[info.label]);
}