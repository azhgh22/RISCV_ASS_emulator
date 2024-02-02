#ifndef azhgh22_sw
#define azhgh22_sw

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
    int offset;
    string from;
} sw;


void* sw_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void sw_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif