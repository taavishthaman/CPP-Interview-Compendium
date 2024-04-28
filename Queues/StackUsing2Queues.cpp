#include<bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q1, q2;
    
public:
    void push(int num) {
        q1.push(num);
    }   
    
    void pop() {
        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        q1.pop();
        
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int top() {
        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        q2.push(res);
        
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        
        return res;
    }
    
    bool empty() {
        return q1.empty();
    }

};

int main() {
    Stack s;
    
    for(int i=1; i<=5; i++) {
        s.push(i);
    }
    
    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }
}