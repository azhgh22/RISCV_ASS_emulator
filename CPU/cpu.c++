#include "cpu.h"

cpu::cpu(){
    registers["ra"]=0;
    registers["pc"]=0;
    registers["sp"]=MEMORY_UPPER_BORDER;
    for(int i=0;i<31;i++){
        string t = "x"+to_string(i);
        registers[t]=0;
    }
}

cpu::~cpu(){

}

bool cpu::check(string rg){
    return registers.find(rg)!=registers.end();
}

int cpu::load_word(string reg){
    return registers[reg];
}

int cpu::load_half(string reg){
    int two_of_32 = 1<<31;
    int mask = two_of_32>>15;
    mask=~mask;
    int value = registers[reg];
    return value&mask;
}

int cpu::load_byte(string reg){
    int two_of_32 = 1<<31;
    int mask = two_of_32>>7;
    mask=~mask;
    int value = registers[reg];
    return value&mask;
}

void cpu::store_word(string reg,int val){
    if(reg=="x0") return;
    registers[reg]=val;
}

void cpu::store_half(string reg,int val){
    if(reg=="x0") return;
    int two_of_32 = 1<<31;
    int mask = two_of_32>>15;
    mask=~mask;
    registers[reg]=val&mask;
}

void cpu::store_byte(string reg,int val){
    if(reg=="x0") return;
    int two_of_32 = 1<<31;
    int mask = two_of_32>>23;
    mask=~mask;
    registers[reg]=val&mask;
}

void cpu::next(int pos){
    if(pos==-1){
        registers["pc"]++;
    }else{
        registers["pc"]=pos;
    }
}