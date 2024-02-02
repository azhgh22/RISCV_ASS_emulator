#ifndef azhgh22_bne
#define azhgh22_bne

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
} bne;


void* bne_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void bne_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif