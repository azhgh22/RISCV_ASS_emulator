#ifndef azhgh22_general_functions
#define azhgh22_general_functions

#include <string>
#include <assert.h>
#include <vector>
#include <iostream>
using namespace std;

typedef struct{
    string type;
    string reg;
    int offset;
    string from;
}load_store;

bool is_number(string s);
int to_number(string s);
void parse_load_store(load_store* info,string line);
string to_lower(string cmd);
bool isLabel(vector<string>& tokens);
void tokenise(vector<string>& tokens,string line);
string remove_comments(string s);
string ltrim(string s);

#endif