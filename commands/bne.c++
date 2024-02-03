#include "bne.h"

void* bne_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    if(tokens.size()!=3){
        throw invalid_argument("Invalid arguments in bne");
    }

    unconfirmed_labels.insert(tokens[2]);
    string f = tokens[0];
    string s = tokens[1];

    bool f_number = is_number(f);

    if(!f_number && !regs.check(f)){
        throw invalid_argument("Invalid arguments in bne");
    }


    bool s_number = is_number(s);
    if(!s_number && !regs.check(s)){
        throw invalid_argument("Invalid arguments in bne");
    }

    bne* st = new bne;

    if(f_number){
        st->f_literal=to_number(f);
        st->f_rg="";
    }else{
        st->f_rg=f;
    }

    if(s_number){
        st->s_literal=to_number(f);
        st->s_rg="";
    }else{
        st->s_rg=s;
    }
    st->label=tokens[2];
    return st;
}

void bne_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    bne info = *(bne*)st;
    string label = info.label;
    
    int f = info.f_rg=="" ? info.f_literal : regs.load_word(info.f_rg);
    int s = info.s_rg=="" ? info.s_literal : regs.load_word(info.s_rg);

    if(f!=s){
        regs.next(labels[label]);
    }else{
        regs.next(-1);
    }

}