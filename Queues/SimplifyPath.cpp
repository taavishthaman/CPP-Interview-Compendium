#include<bits/stdc++.h>
using namespace std;

vector<string> tokenize(string str) {
    vector<string> tokens;
    string token;
    stringstream ss(str);
    
    while(getline(ss, token, '/')) {
        if(token == "." || token == "") {
            continue;
        }
        tokens.push_back(token);
    }
    
    return tokens;
}

string simplifyPath(string str) {
    vector<string> tokens = tokenize(str);
    
    vector<string> stack;
    
    if(str[0] == '/') {
        stack.push_back("");
    }
    
    for(string token : tokens) {
        if(token == "..") {
            if(stack.size() == 0 || stack[stack.size() - 1] == "..") {
                stack.push_back("..");
            } else if(stack[stack.size()-1] != ""){
                stack.pop_back();
            }
        } else {
            stack.push_back(token);
        }
    }
    
    string op = "";
    int i=0;
    if(str[0] == '/') {
        op += '/';
        i++;
    }
    for(;i<stack.size(); i++) {
        op += stack[i];
        op += '/';
        if(i == stack.size()-1) {
            op.pop_back();
        }
    }
    
    return op;
}

int main() {
    string str = "/a/./b/./c/./d/";
    string op = simplifyPath(str);
    cout<<op<<endl;
}