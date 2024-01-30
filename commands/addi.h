#ifndef azhgh22_addi
#define azhgh22_addi

#include <iostream>
#include <map>
#include "memory/memory.h"

using namespace std;

typedef struct
{
    /* data */
    string store_rg;
    string first_rg;
    int constant;
} addi;


void* addi_init();
void addi_run(void* st,map<string,int>& registers,Memory& mem);


#endif