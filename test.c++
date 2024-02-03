#include <bits/stdc++.h>
using namespace std;

void change(vector<int>* a){
    a->push_back(39);
}

int p(){
    int a = 1<<31;
    int* b = &a;
    return *(short*)b;
}

string to_lower(string cmd){
    for(int i=0;i<cmd.size();i++){
        if(cmd[i]>='A' && cmd[i]<='Z'){
            cmd[i]=(char)('a'+cmd[i]-'A');
        }
    }
    return cmd;
}

int main(){
    cout<<"\""<<endl;
}