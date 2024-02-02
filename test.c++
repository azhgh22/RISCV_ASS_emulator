#include <bits/stdc++.h>
#include "commands/general_functions.h"
using namespace std;

void change(vector<int>* a){
    a->push_back(39);
}

int p(){
    int a = 1<<31;
    int* b = &a;
    return *(short*)b;
}

int main(){
    load_store* info = new load_store;
    info->type="sw";
    parse_load_store(info,"x14    1(sp    )");
    cout<<info->type<<" "<<info->reg<<" "<<info->offset<<"("<<info->from<<")"<<endl;
}