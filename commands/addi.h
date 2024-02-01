#ifndef azhgh22_addi
#define azhgh22_addi

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
    string first_rg;
    int literal;
    string label;
} addi;


void* addi_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void addi_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif