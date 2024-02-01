#ifndef azhgh22_li
#define azhgh22_li

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
    string store_rg;
    int literal;
    string label;
} li;


void* li_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void li_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif