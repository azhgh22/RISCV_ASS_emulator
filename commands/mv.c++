#include "mv.h"

void* mv_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    if(tokens.size()!=2){
        throw invalid_argument("Invalid arguments in ADD");
    }

    string rd = tokens[0];
    string rs = tokens[1];

    if(!regs.check(rd)){
        throw invalid_argument("register "+rd+" does not exist");
    }

    if(!regs.check(rs)){
        throw invalid_argument("register "+rs+" does not exist");
    }

    mv* st = new mv;
    st->rd=rd;
    st->rs=rs;
    return st;
}


void mv_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    mv info = *(mv*)st;
    regs.store_word(info.rd,regs.load_word(info.rs));
    regs.next(-1);
}