#ifndef azhgh22_ble
#define azhgh22_ble

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
} ble;


void* ble_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void ble_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif