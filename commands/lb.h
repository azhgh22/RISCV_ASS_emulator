#ifndef azhgh22_lb
#define azhgh22_lb

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
} lb;


void* lb_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void lb_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif