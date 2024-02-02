#ifndef azhgh22_beq
#define azhgh22_beq

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
    string f_rg;
    string s_rg;
    string label;
    int f_literal;
    int s_literal;
} beq;


void* beq_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void beq_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif