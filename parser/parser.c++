#include "parser.h"

Parser::Parser(string file_path){
    ifstream f(file_path);
    string line;

    while(getline(f,line)){
        parse_line(line);
    }
    
    f.close();
}

Parser::~Parser(){

}

void Parser::parse_line(string line){
    // parse line and add appropriate command to vector
}