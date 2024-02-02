#include "ret.h"

void* ret_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    ret* st = new ret;
    return st;
}

void ret_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    int pos = regs.load_word("ra");
    regs.next(pos);
}