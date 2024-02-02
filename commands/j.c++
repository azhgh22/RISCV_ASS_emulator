#include "j.h"

void* j_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    if(tokens.size()!=1) __throw_invalid_argument("invalid arguments in call");
    unconfirmed_labels.insert(tokens[0]);
    j* st = new j;
    st->label = tokens[0];
    return st;
}

void j_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    j info = *(j*)st;
    regs.next(labels[info.label]);
}