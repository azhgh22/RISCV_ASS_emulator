#ifndef azhgh22_jalr
#define azhgh22_jalr

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
    string rg;
} jalr;


void* jalr_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void jalr_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif