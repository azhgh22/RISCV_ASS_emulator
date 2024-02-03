#ifndef azhgh22_print
#define azhgh22_print

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
    string text;
} print;


// usage : 

// print "str"

void* print_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void print_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif