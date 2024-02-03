#ifndef azhgh22_ecall
#define azhgh22_ecall

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "../memory/memory.h"
#include "../CPU/cpu.h"
#include "general_functions.h"

using namespace std;


void* ecall_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void ecall_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif