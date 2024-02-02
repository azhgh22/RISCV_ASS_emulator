#include "call.h"

void* call_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    if(tokens.size()!=1) __throw_invalid_argument("invalid arguments in call");
    unconfirmed_labels.insert(tokens[0]);
    call* st = new call;
    st->label=tokens[0];
    return st;
}

void call_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    call info = *(call*)st;
    int pc = regs.load_word("pc");
    pc++;
    regs.store_word("ra",pc);
    regs.next(labels[info.label]);
}