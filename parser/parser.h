#ifndef azhgh22_parser
#define azhgh22_parser

#include <vector>
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <stdexcept>
#include "../memory/memory.h"
#include "../CPU/cpu.h"
#include "includes.h"
#include "../commands/general_functions.h"
using namespace std;

typedef struct 
{
    string type;   
    void* cmd_ptr;
}Command;


typedef void* (*INSTR_INIT)(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
typedef void (*INSTR_RUN)(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);

class Parser{

private:
    map<string,INSTR_INIT> cmd_inits;
    map<string,INSTR_RUN> cmd_runs;
    set<string> unconfirmed_labels;
    map<string,unsigned int> labels;
    vector<Command> cmd_queue;
    set<string> general_strings;
    Memory* mem;
    cpu* regs;
    void parse_line(string line);
    void init_cmds();
    void put_inits();
    void put_runs();
    void analise_labels();
    void init_genral_strings();
public:
    Parser(string file_path,Memory* mem,cpu* regs);
    ~Parser();
    void print();
    void run(int cmd_idx);
    unsigned int count_cmds();
};

#endif