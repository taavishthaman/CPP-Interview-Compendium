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

int main() {
    stack<int> s;
    
    for(int i=1; i<=5; i++) {
        s.push(i);
    }
    
    insertAtBottom(s, 20);
    
    while(!s.empty()) {
        cout<<s.top()<<",";
        s.pop();
    }
}