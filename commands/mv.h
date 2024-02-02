#ifndef azhgh22_mv
#define azhgh22_mv

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
    string rd;
    string rs;
} mv;


void* mv_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels);
void mv_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels);


#endif