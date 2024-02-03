#ifndef azhgh22_ret
#define azhgh22_ret

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "../memory/memory.h"
#include "../CPU/cpu.h"
#include "general_functions.h"

using namespace std;


void* ret_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void ret_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif