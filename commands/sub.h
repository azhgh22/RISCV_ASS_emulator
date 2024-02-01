#ifndef azhgh22_sub
#define azhgh22_sub

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
    string second_rg;
} sub;


void* sub_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void sub_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif