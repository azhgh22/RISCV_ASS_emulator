#include "lw.h"

void* lw_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    line = line.size()>2 ? line.substr(2):"";
    line = ltrim(line);
    load_store* info = new load_store;
    info->type = "sw";
    parse_load_store(info,line);
    if(!regs.check(info->reg) || !regs.check(info->from)){
        __throw_invalid_argument("invalid registers in sw");
    }
    lw* st = new lw;
    st->from=info->from;
    st->offset=info->offset;
    st->rg=info->reg;
    delete info;
    return st;
}

void lw_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    lw info = *(lw*)st;
    int from = regs.load_word(info.from);
    int val = mem.load_word(info.offset,from);
    regs.store_word(info.rg,val);
    regs.next(-1);
}