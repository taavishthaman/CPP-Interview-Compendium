#include<bits/stdc++.h>
using namespace std;

int cntSubarrays(vector<int> arr,int k){
    //complete this method
    int n = arr.size();
    vector<int> prefix(n, 0);
    unordered_map<int, int> m;
    
    prefix[0] = arr[0];
    m[arr[0]] = 1;
    int count = 0;
    if(arr[0] == k) {
        count++;
    }
    for(int i=1; i<n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
        if(m.find(prefix[i]-k) != m.end()) {
            count += m[prefix[i]-k];
        }
        if(prefix[i] == k) {
            count++;
        }
        m[prefix[i]]++;
    }
    
    return count;
}

int main() {
    vector<int> v = {10, 2, -2, -20, 10};
    int k = -10;
    cout<<cntSubarrays(v, k)<<endl;
}