#ifndef azhgh22_parser
#define azhgh22_parser

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

typedef struct 
{
    int type;   
    void* cmd_ptr;
}Command;



class Parser{

private:
    vector<Command> cmd_queue;
    void parse_line(string line);

public:
    Parser(string file_path);
    ~Parser();
};

#endif