#include "memory.h"

Memory::Memory(){
    base = (char*)malloc(20000);
}
 
Memory::~Memory(){
    free(base);
}

int Memory::load_word(int offset,int from){
    char* ptr = base+from+offset;
    return *(int*)ptr;
}

int Memory::load_half(int offset,int from){
    char* ptr = base+from+offset;
    return *(short*)ptr;
}

int Memory::load_byte(int offset,int from){
    char* ptr = base+from+offset;
    return *ptr;
}
    
void Memory::store_word(int offset,int from,int val){
    char* ptr = base+from+offset;
    *(int*)ptr = val;
}
    
void Memory::store_half(int offset,int from,int val){
    char* ptr = base+from+offset;
    *(short*)ptr = val;
}
    
void Memory::store_byte(int offset,int from,int val){
    char* ptr = base+from+offset;
    *ptr = val;
}