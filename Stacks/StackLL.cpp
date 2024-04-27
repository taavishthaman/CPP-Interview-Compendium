#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node * next;
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
    Node * head = NULL;
    
public:
    bool empty() {
        return head == NULL;
    }
    
    void push(int val) {
        Node * n = new Node(val);
        n->next = head;
        head = n;
    }
    
    void pop() {
        Node * temp = head;
        head = head->next;
        delete temp;
    }
    
    int top() {
        return head->data;
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


