#ifndef azhgh22_jal
#define azhgh22_jal

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
    string label;
} jal;


void* jal_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void jal_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif