#include<bits/stdc++.h>
using namespace std;

class Stack {
    vector<int> arr;
    
public:
    void push(int data) {
        arr.push_back(data);
    }
    
    void pop() {
        arr.pop_back();
    }
    
    int top() {
        return arr[arr.size()-1];
    }
    
    bool empty() {
        return arr.size() == 0;
    }
};

int main() {
    Stack s;
    
    for(int i=1; i<=5; i++) {
        s.push(i);
    }
    
    while(!s.empty()) {
        cout<<s.top()<<",";
        s.pop();
    }
}