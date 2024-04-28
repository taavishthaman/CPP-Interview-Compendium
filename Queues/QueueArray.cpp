#include<bits/stdc++.h>
using namespace std;

// If you are implement a queue using an array, you can only do so using a circular array
class Queue {
    int * arr;
    int cs;
    int ms;
    int front;
    int rear;
    
public:
    Queue(int default_size = 5) {
        ms = default_size;
        cs = 0;
        arr = new int[ms];
        front = 0;
        rear = ms - 1;
    }
    
    bool full() {
        return cs == ms;
    }
    
    bool empty() {
        return cs == 0;
    }
    
    void enqueue(int data) {
        if(!full()) {
            rear = (rear + 1) % ms;
            arr[rear] = data;
            cs++;
        }
    }
    
    void dequeue() {
        if(!empty()) {
            front = (front + 1) % ms;
            cs--;
        }
    }
    
    int getFront() {
        return arr[front];
    }
};

int main() {
    Queue q(7);
    
    for(int i=1; i<=8; i++) {
        q.enqueue(i);
    }
    
    q.dequeue();
    q.dequeue();
    q.enqueue(9);
    
    while(!q.empty()) {
        cout<<q.getFront()<<", ";
        q.dequeue();
    }
}