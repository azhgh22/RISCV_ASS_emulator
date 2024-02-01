#ifndef azhgh22_cpu
#define azhgh22_cpu

#include <iostream>
#include <map>
#include "../memory/memory.h"

using namespace std;

#define MEMORY_UPPER_BORDER 20000

class cpu{
private:
    map<string,int> registers;
public:
    cpu();
    ~cpu();
    bool check(string rg);
    int load_word(string reg);
    int load_half(string reg);
    int load_byte(string reg);
    void store_word(string reg,int val);
    void store_half(string reg,int val);
    void store_byte(string reg,int val);
    void next(int pos);
};

#endif