#include "general_functions.h"

bool is_number(string s){
    return s.find_first_not_of("-1234567890")==string::npos;
}

int to_number(string s){
    if(s[0]=='-'){
        return -1*to_number(s.substr(1));
    }
    int ans = 0;
    for(int i=0;i<s.size();i++){
        ans*=10;
        ans+=(s[i]-'0');
    }
    return ans;
}