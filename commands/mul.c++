#include "mul.h"

void* mul_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    if(tokens.size()!=3){
        throw invalid_argument("Invalid arguments in ADD");
    }

    string st_rg = tokens[0];
    string f_rg = tokens[1];
    string s_rg = tokens[2];

    if(!regs.check(st_rg)){
        throw invalid_argument("register "+st_rg+" does not exist");
    }

    if(!regs.check(f_rg)){
        throw invalid_argument("register "+f_rg+" does not exist");
    }

    if(!regs.check(s_rg)){
        throw invalid_argument("register "+s_rg+" does not exist");
    }

    mul* st = new mul;
    st->store_rg=st_rg;
    st->first_rg=f_rg;
    st->second_rg=s_rg;

    return st;
}

void mul_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    mul info = *(mul*)st;
    int f_val = regs.load_word(info.first_rg);
    int s_val = regs.load_word(info.second_rg);
    int result = f_val*s_val;
    regs.store_word(info.store_rg,result);
    regs.next(-1);
}