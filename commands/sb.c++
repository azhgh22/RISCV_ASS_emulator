#include "sb.h"

void* sb_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    line = line.size()>2 ? line.substr(2):"";
    line = ltrim(line);
    load_store* info = new load_store;
    info->type = "sw";
    parse_load_store(info,line);
    if(!regs.check(info->reg) || !regs.check(info->from)){
        __throw_invalid_argument("invalid registers in sw");
    }
    sb* st = new sb;
    st->from=info->from;
    st->offset=info->offset;
    st->rg=info->reg;
    delete info;
    return st;
}

void sb_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    sb info = *(sb*)st;
    int from = regs.load_word(info.from);
    int val = regs.load_word(info.rg);
    mem.store_byte(info.offset,from,val);
    regs.next(-1);
}