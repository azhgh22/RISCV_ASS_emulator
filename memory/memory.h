#ifndef azhgh22_memory
#define azhgh22_memory

#include <iostream>

class Memory{

private:
    char* base;

public:
    Memory();
    ~Memory();
    int load_word(int offset,int from);
    int load_half(int offset,int from);
    int load_byte(int offset,int from);
    void store_word(int offset,int from,int val);
    void store_half(int offset,int from,int val);
    void store_byte(int offset,int from,int val);
};

#endif