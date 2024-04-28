#include <bits/stdc++.h>
using namespace std;

bool balanced_parentheses(string str) {
    int n = str.size();
    stack<char> s;
    
    for(int i=0; i<n; i++) {
        char ch = str[i];
        
        if(ch == '{' || ch == '(' || ch == '[') {
            s.push(ch);
        } else if(ch == '}' || ch == ']' || ch == ')') {
            if(!s.empty() && ((ch == ')' && s.top() == '(') || 
            (ch == ']' && s.top() == '[') || 
            (ch == '}' && s.top() == '{'))) {
                s.pop();
            } else {
                return false;
            }
        }
    }
    
    return s.empty();
}

int main()
{
    vector<string> test = {"((a+b)*x-d)", "((a+b]+c)*(d-e)"};

    for(string str : test) {
        cout<<balanced_parentheses(str)<<endl;
    }
    return 0;
}
