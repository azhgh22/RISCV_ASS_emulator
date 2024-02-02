#ifndef azhgh22_call
#define azhgh22_call

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
} call;


void* call_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void call_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif