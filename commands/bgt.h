#ifndef azhgh22_bgt
#define azhgh22_bgt

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
} bgt;


void* bgt_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void bgt_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif