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

int main(){
    char* base = (char*)malloc(5);
    for(int i=0;i<5;i++){
        base[i]=0;
    }

    for(int i=0;i<5;i++){
        cout<<i<<" "<<base[i]<<endl;
    }

    int l = -1;
    base[0]=l;


    for(int i=0;i<5;i++){
        cout<<i<<" "<<base[i]<<endl;
    }

}