#include<bits/stdc++.h>
using namespace std;

int longest_chain(vector<int> & arr) {
    int n = arr.size();
    
    unordered_set<int> s;
    for(int i=0; i<n; i++) {
        s.insert(arr[i]);
    }
    
    int largest_chain = 0;
    for(int i=0; i<n; i++) {
        if(s.find(arr[i]-1) == s.end()) {
            //This number can start a chain
            int cnt = 0;
            int curr = arr[i];
            while(s.find(curr) != s.end()) {
                curr++;
                cnt++;
            }
            
            largest_chain = max(largest_chain, cnt);
        }
    }
    
    return largest_chain;
}

int main() {
    vector<int> v = {0,3,7,2,5,8,4,6,0,1};
    int res = longest_chain(v);
    cout<<res<<endl;
}