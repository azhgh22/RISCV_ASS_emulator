#include "general_functions.h"

bool is_number(string s){
    if(s=="") return false;
    if(s[0]=='-') return is_number(s.substr(1));
    if(s.size()!=1 && s[0]=='0') return false;
    return s.find_first_not_of("1234567890")==string::npos;
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


string find_reg(string& line,string type){
    string error = string("invlaid arguments in: ")+type;
    int end_idx = line.find_first_of(" ,");
    if(end_idx==string::npos) __throw_invalid_argument(error.c_str());
    string ret_val = line.substr(0,end_idx);
    line = line.substr(end_idx);
    return ret_val;
}

int find_num(string& line,string type){
    string error = string("invlaid arguments in: ")+type;
    int check_minus = line.find("-");
    if(check_minus!=string::npos) __throw_invalid_argument(error.c_str());
    int start_idx = line.find_first_of("0123456789"); 
    if(start_idx==string::npos) __throw_invalid_argument(error.c_str());
    line=line.substr(start_idx);
    int end_idx = line.find_first_of(" (");
    if(start_idx==string::npos) __throw_invalid_argument(error.c_str());
    string number = line.substr(0,end_idx);
    if(is_number(number)){
        line = line.substr(end_idx);
        return to_number(number);
    }else{
        __throw_invalid_argument(error.c_str());
    }
}

string find_from_reg(string& line,string type){
    string error = string("invlaid arguments in: ")+type;
    int start_idx = line.find_first_not_of(" (");
    if(start_idx==string::npos) __throw_invalid_argument(error.c_str());
    line=line.substr(start_idx);
    int end_idx = line.find_first_of(" )");
    if(end_idx==string::npos) __throw_invalid_argument(error.c_str());
    string from = line.substr(0,end_idx);
    line = line.substr(end_idx);
    int ch_idx = line.find_first_not_of(" )");
    if(ch_idx!=string::npos) __throw_invalid_argument(error.c_str());
    return from;
}

void parse_load_store(load_store* info,string line){
    info->reg = find_reg(line,info->type);
    info ->offset = find_num(line,info->type);
    info->from = find_from_reg(line,info->type);
}

///////

string ltrim(string s){
    size_t idx = s.find_first_not_of(" \t\r");
    if(idx!=string::npos){
        return s.substr(idx);
    }

    return s;
}

string remove_comments(string s){
    size_t idx = s.find_first_of("#");
    if(idx!=string::npos){
        return s.substr(0,idx);
    }
    return s;
}

void tokenise(vector<string>& tokens,string line){
    string word = "";
    for(int i=0;i<line.size();i++){
        if((line[i]==' ' || line[i]==',') && word!=""){
            tokens.push_back(word);
            word="";
        }else if(line[i]!=' ' && line[i]!=','){
            word+=line[i];
        }
    }

    if(word!=""){
        tokens.push_back(word);
    }
}


bool isLabel(vector<string>& tokens){
    if(tokens.size()==0) return false;
    if(tokens.size()>1){
        if(tokens[1]==":"){
            tokens.erase(tokens.begin()+1);
            tokens[0]+=":";
            return true;
        }

        if(tokens[0][tokens[0].size()-1]==':'){
            return true;
        }

        return false;
    }else{
        if(tokens[0][tokens[0].size()-1]==':'){
            return true;
        }
        return false;
    }
}

string to_lower(string cmd){
    for(int i=0;i<cmd.size();i++){
        if(cmd[i]>='A' && cmd[i]<='Z'){
            cmd[i]=(char)('a'+cmd[i]-'A');
        }
    }
    return cmd;
}

bool is_char(string s){
    return s.size()==3 && s[0]=='\'' && s[2]=='\'';
}