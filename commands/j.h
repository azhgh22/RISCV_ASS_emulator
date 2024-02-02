#ifndef azhgh22_j
#define azhgh22_j

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
    string label;
} j;


void* j_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void j_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif