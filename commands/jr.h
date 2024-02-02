#ifndef azhgh22_jr
#define azhgh22_jr

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
} jr;


void* jr_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void jr_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif