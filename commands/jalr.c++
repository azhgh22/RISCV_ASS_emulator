#include "jalr.h"

void* jalr_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    if(tokens.size()!=1) __throw_invalid_argument("invalid arguments in call");
    if(!regs.check(tokens[0])) __throw_invalid_argument("invalid arguments in call");

    jalr* st = new jalr;
    st->rg=tokens[0];
    return st;
}

void jalr_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    jalr info = *(jalr*)st;
    int pc = regs.load_word("pc");
    pc++;
    regs.store_word("ra",pc);
    int pos = regs.load_word(info.rg);
    regs.next(pos);
}