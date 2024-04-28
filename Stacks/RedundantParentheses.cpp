#include<bits/stdc++.h>
using namespace std;

bool redundantParentheses(string str) {
    int n = str.size();
    stack<char> s;
    
    for(int i=0; i<n; i++) {
        char ch = str[i];
        
        if(ch != ')') {
            s.push(ch);
        } else {
            bool operator_found = false;
            while(!s.empty() && s.top() != '(') {
                char top = s.top();
                if(top == '+' || top == '-' || top == '/' || top == '*') {
                    operator_found = true;
                }
                s.pop();
            }
            s.pop();
            
            if(operator_found == false) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    string str = "((a+b)+c)+((d*e))";
    bool res = redundantParentheses(str);
    if(res == true) {
        cout<<"Redundant Brackets Found!"<<endl;
    } else {
        cout<<"No Redundant Brackets Found!"<<endl;
    }
}