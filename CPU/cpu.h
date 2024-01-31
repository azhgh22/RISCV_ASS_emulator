#ifndef azhgh22_cpu
#define azhgh22_cpu

#include <iostream>
#include <map>
#include "../memory/memory.h"

using namespace std;

class cpu{
private:
    map<string,int> registers;
public:
    cpu();
    ~cpu();
    bool check(string rg);
};

#endif