#include "print.h"

size_t parse_string(string line){
    size_t ans = string::npos;
    for(int i=0;i<line.size();i++){
        if(line[i]=='\"'){
            if(i==0){
                i=ans;
            }
            else if(line[i-1]!='\\'){
                ans=i;
                break;;
            }
        }
    }
    if(ans==string::npos) return ans;

    if(ans==line.size()-1) return ans;
    line = line.substr(ans+1);    
    int ch_idx = line.find_first_not_of(" \t\r");
    if(ch_idx!=string::npos){
        ans = string::npos;
    }

    return ans;
}

void* print_init(vector<string>& tokens,string line,cpu& regs,set<string>& unconfirmed_labels){
    int st_idx = line.find_first_of("\"");
    if(st_idx==string::npos) __throw_invalid_argument("invlaid arguments in print");
    if(st_idx==line.size()-1) __throw_invalid_argument("invlaid arguments in print");
    line = line.substr(st_idx+1);
    int end_idx = parse_string(line);
    if(end_idx==string::npos) __throw_invalid_argument("invlaid arguments in print");
    print* st = new print;
    st->text = line.substr(0,line.find_last_of("\""));
    return st;
}

void print_run(void* st,cpu& regs,Memory& mem,map<string,unsigned int>& labels){
    print info = *(print*)st;
    cout<<info.text;
    regs.next(-1);
}