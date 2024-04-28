#include<bits/stdc++.h>
using namespace std;

void findMaxInWindow(vector<int> & v, int k) {
    deque<int> q;
    int i = 0;
    int n = v.size();
    for(i=0; i<k; i++) {
        //Remove all elements from the back of the deque which are smaller than the current element since
        //they are not useful for us since they will not appear in the current window
        while(!q.empty() && v[q.back()] <= v[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    
    for(;i<n; i++) {
        //Print the front element of deque
        cout<<v[q.front()]<<", ";
        //Remove all elements which lie outside the window
        while(!q.empty() && q.front() <= i-k) {
            q.pop_front();
        }
        while(!q.empty() && v[q.back()] <= v[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<v[q.front()]<<endl;
}

int main() {
    vector<int> v = {1,2,3,1,4,5,2,3,5};
    findMaxInWindow(v, 3);
}