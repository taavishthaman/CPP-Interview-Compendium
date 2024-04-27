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

class LinkedList {
public:
    Node * head = NULL;
    Node * tail = NULL;
    
    void push_back(int data) {
        if(head == NULL) {
            Node * n = new Node(data);
            head = n;
            tail = n;
        } else {
            Node * n = new Node(data);
            tail->next = n;
            tail = n;
        }
    }
    
    void push_front(int data) {
        if(head == NULL) {
            Node * n = new Node(data);
            head = n;
            tail = n;
        } else {
            Node * n = new Node(data);
            n->next = head;
            head = n;
        }
    }
    
    void print() {
        Node * ptr = head;
        
        while(ptr != NULL) {
            cout<<ptr->data<<"-->";
            ptr = ptr->next;
        }
        cout<<endl;
    }
};


Node * mergeList(Node * l1, Node * l2) {
    if(l1 == NULL) {
        return l2;
    }
    if(l2 == NULL) {
        return l1;
    }
    
    Node * n;
    
    if(l1->data < l2->data) {
        n = new Node(l1->data);
        n->next = mergeList(l1->next, l2);
    } else {
        n = new Node(l2->data);
        n->next = mergeList(l1, l2->next);
    }
    
    return n;
}

Node * findMid(Node * head) {
    Node * slow = head;
    Node * fast = head;
    
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

Node * mergeSort(Node * head) {
    if(head == NULL || head->next == NULL) return head;
    
    Node * mid = findMid(head);
    Node * head2 = mid->next;
    mid->next = NULL;
    
    Node * n1 = mergeSort(head);
    Node * n2 = mergeSort(head2);
    return mergeList(n1, n2);
}

int main() {
   LinkedList l;
   for(int i=7; i>=1; i--) {
       l.push_back(i);
   }
   
   l.print();
   
   Node * nh = mergeSort(l.head);
   
   Node * ptr = nh;
   
   while(ptr != NULL) {
        cout<<ptr->data<<"-->";
        ptr = ptr->next;
   }
}