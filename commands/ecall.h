#ifndef azhgh22_print
#define azhgh22_print

#include <iostream>
#include <map>
#include "memory/memory.h"

using namespace std;


void* print_init();
void print_run(void* st,map<string,int>& registers,Memory& mem);


#endif