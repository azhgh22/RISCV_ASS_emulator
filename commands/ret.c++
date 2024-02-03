#include "ret.h"

void* ret_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    if(tokens.size()!=0) __throw_invalid_argument("invalid arguments in ret");
    return nullptr;
}

void ret_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    int pos = regs.load_word("ra");
    regs.next(pos);
}