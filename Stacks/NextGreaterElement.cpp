#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterToRight(vector<int> v) {
    int n = v.size();
    stack<int> s;
    vector<int> op;
    
    op.push_back(n);
    s.push(n-1);
    
    for(int i=n-2; i>=0; i--) {
        int curr = v[i];
        while(!s.empty() && curr >= v[s.top()]) {
            s.pop();
        }
        
        if(s.empty()) {
            op.insert(op.begin(), n);
        } else {
            op.insert(op.begin(), s.top());
        }
        
        s.push(i);
    }
    
    return op;
}

vector<int> nextGreaterElement(vector<int> v){
    int n = v.size();
    vector<int> ngr = nextGreaterToRight(v);
    vector<int> op;
    for(int i=0; i<n; i++) {
        if(ngr[i] == n) {
            op.push_back(-1);
        } else {
            op.push_back(v[ngr[i]]);
        }
    }
    
    return op;
}

int main() {
    vector<int> v = {4, 5, 2, 25};
    vector<int> op = nextGreaterElement(v);
    
    for(int num : op) {
        cout<<num<<", ";
    }
}