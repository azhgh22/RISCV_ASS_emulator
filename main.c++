#include <iostream>
#include <stdexcept>
#include <fstream>
#include "parser/parser.h"
#include "CPU/cpu.h"
#include "memory/memory.h"
using namespace std;

string get_file_name(int argc,char** argv){
    if(argc!=2){
        throw invalid_argument("incorect number of arguments!!!");
    }

    string file_path = argv[1];
    ifstream f(file_path);

    if(!f.good()){
        throw invalid_argument("file does not exist!!!");
    }

    f.close();
    return file_path;
}

int main(int argc,char* argv[]){
    string file = get_file_name(argc,argv);
    
    Memory m;
    cpu c;
    Parser p(file,&m,&c);

    // while(c.getProgramCounter()!=p.vector().size()){
    //     Command cmd = p.vector[c.getProgramCounter()];
    //     c.cmd_runs(&cmd.cmd_ptr,c.registers,m);
    // }



}