#include "jr.h"

void* jr_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    if(tokens.size()!=1) __throw_invalid_argument("invalid arguments in call");
    if(!regs.check(tokens[0])) __throw_invalid_argument("invalid arguments in call");

    jr* st = new jr;
    st->rg=tokens[0];
    return st;
}

void jr_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    jr info = *(jr*)st;
    int pos = regs.load_word(info.rg);
    regs.next(pos);
}