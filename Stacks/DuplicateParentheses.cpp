#include<bits/stdc++.h>
using namespace std;

bool duplicateParentheses(string str){
    int n = str.size();
    stack<char> s;
    
    for(int i=0; i<n; i++) {
        char ch = str[i];
        
        if(ch != ')' && ch != '}' && ch != ']') {
            s.push(ch);
        } else {
            if((ch == ')' && s.top() == '(') || (ch == ']' && s.top() == '[') || (ch == '}' && s.top() == '{')) {
                return true;
            } else {
                while(!s.empty() && (s.top() != '(' && s.top() != '{' && s.top() != '[')) {
                    s.pop();
                }
                
                if(!s.empty()) s.pop();
            }
        }
    }
    
    return false;
}

int main() {
    string str = "(((a+(b))+c+d))";
    bool is_duplicate = duplicateParentheses(str);
    
    cout<<is_duplicate<<endl;
}
