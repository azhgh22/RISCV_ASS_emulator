#ifndef azhgh22_add
#define azhgh22_add

#include <iostream>
#include <map>
#include "memory/memory.h"

using namespace std;

typedef struct
{
    /* data */
    string store_rg;
    string first_rg;
    string second_rg;
} add;


void* add_init();
void add_run(void* st,map<string,int>& registers,Memory& mem);


#endif