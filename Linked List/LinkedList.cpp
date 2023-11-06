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
    
    ~Node() {
        if(next != NULL) {
            delete next;   
        }
    }
};

class List {
public:
    Node * head;
    Node * tail;
    
    List() {
        head = tail = NULL;
    }
    
    void push_front(int data) {
        if(head == NULL) {
            Node * n = new Node(data);
            head = tail = n;
        } else {
            Node * n = new Node(data);
            n->next = head;
            head = n;
        }
    }
    
    void push_back(int data) {
        if(head == NULL) {
            Node * n = new Node(data);
            head = tail = n;
        } else {
            Node * n = new Node(data);
            tail->next = n;
            tail = n;
        }
    }
    
    void insert(int data, int pos) {
        if(pos == 0) {
            push_front(data);
        } else {
            Node * temp = head;
            for(int i=1; i<=pos-1; i++) {
                temp = temp->next;
            }
            
            Node * n = new Node(data);
            n->next = temp->next;
            temp->next = n;
        }
    }
    
    void print() {
        Node * temp = head;
        
        while(temp != NULL) {
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
    }
    
    void pop_front() {
        Node * temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    
    void pop_back() {
        Node * temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        
        Node * n = temp->next;
        temp->next = NULL;
        tail = temp;
        delete n;
    }
    
    void pop_middle(int pos) {
        Node * temp = head;
        
        for(int i=1; i<=pos-1; i++) {
            temp = temp->next;
        }
        
        Node * n = temp->next;
        temp->next = n->next;
        n->next = NULL;
        delete n;
    }
    
    void reverse() {
        Node * p = NULL;
        Node * c = head;
        Node * n = NULL;
        
        tail = c;
        
        while(c != NULL) {
            n = c->next;
            
            c->next = p;
            p = c;
            c = n;
        }
        
        head = p;
    }
    
    Node* k_reverse(Node * head, int k) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        Node * p = NULL;
        Node * c = head;
        Node * n = NULL;
        int cnt = 1;
        
        //1->2->3->4->5
        while(c != NULL && cnt <= k) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
            
            cnt++;
        }
        
        if(c != NULL) {
            head->next = k_reverse(c, k);
        }
        
        return p;
    }
    
    ~List() {
        if(head != NULL) {
            delete head;
            head = NULL;
        }
    }
};

int main() {
    List l;
    for(int i=1; i<=5; i++) {
        l.push_back(i);
    }
    
    //l.insert(10, 2);
    // l.pop_front();
    //l.pop_back();
    //l.pop_middle(1);
    // l.reverse();
    // l.reverse();
    // l.print();
    Node * nh = l.k_reverse(l.head, 3);
    
    while(nh != NULL) {
        cout<<nh->data<<"-->";
        nh = nh->next;
    }
}   