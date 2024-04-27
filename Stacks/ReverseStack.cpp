#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> & s, int num) {
    
    if(s.empty()) {
        s.push(num);
        return;
    }
    
    int curr = s.top();
    s.pop();
    insertAtBottom(s, num);
    s.push(curr);
}

void reverseStack(stack<int> & s) {
    if(s.empty()) return;
    
    int curr = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, curr);
}

int main() {
    stack<int> s;
    
    for(int i=1; i<=5; i++) {
        s.push(i);
    }
    
    reverseStack(s);
    
    while(!s.empty()) {
        cout<<s.top()<<", ";
        s.pop();
    }
}