#ifndef azhgh22_mul
#define azhgh22_mul

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "../memory/memory.h"
#include "../CPU/cpu.h"

using namespace std;

typedef struct
{
    /* data */
    string store_rg;
    string first_rg;
    string second_rg;
} mul;


void* mul_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void mul_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif