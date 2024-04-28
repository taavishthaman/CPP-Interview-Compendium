#include <bits/stdc++.h>
using namespace std;

queue<int> interLeave(queue<int> q){
    queue<int> q_left;
    queue<int> q_right;
    
    int n = q.size();
    int m = n / 2;
    
    while(m > 0) {
        q_left.push(q.front());
        q.pop();
        m--;
    }
    
    m = n / 2;
    
    while(m > 0) {
        q_right.push(q.front());
        q.pop();
        m--;
    }
    
    while(!q_left.empty()) {
        q.push(q_left.front());
        q.push(q_right.front());
        q_right.pop();
        q_left.pop();
    }
    
    return q;
}