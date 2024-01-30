#ifndef azhgh22_cpu
#define azhgh22_cpu

#include <iostream>
#include <map>
#include "memory/memory.h"

using namespace std;

typedef void* (*INSTR_INIT)();
typedef void (*INSTR_RUN)(void* st,map<string,int>& registers,Memory& mem);

class cpu{
private:
    map<string,INSTR_INIT> cmd_inits;
    map<string,INSTR_RUN> cmd_runs;
    map<string,int> registers;
public:
    cpu();
    ~cpu();

};

#endif