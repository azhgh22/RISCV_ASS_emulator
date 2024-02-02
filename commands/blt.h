#ifndef azhgh22_blt
#define azhgh22_blt

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "../memory/memory.h"
#include "../CPU/cpu.h"
#include "general_functions.h"

using namespace std;

typedef struct
{
    /* data */
    string f_rg;
    string s_rg;
    string label;
    int f_literal;
    int s_literal;
} blt;


void* blt_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void blt_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif