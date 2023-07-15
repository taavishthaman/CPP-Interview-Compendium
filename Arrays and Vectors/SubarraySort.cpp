#include<bits/stdc++.h>
using namespace std;

bool outOfOrder(vector<int> & v, int i) {
    int n = v.size();
    if(i == 0) {
        if(v[i] > v[i+1]) {
            return true;
        }
    }
    else if(i == n-1) {
        if(v[i] < v[i-1]) {
            return true;
        }
    }
    else if(i > 0 && i < n-1){
        if(v[i] < v[i-1] || v[i] > v[i+1]) {
            return true;
        }
        return false;
    }
    
    return false;
}

pair<int, int> subarraySort(vector<int> & v) {
    int n = v.size();
    int min_ele = INT_MAX;
    int max_ele = INT_MIN;
    
    for(int i=0; i<n; i++) {
        if(outOfOrder(v, i)) {
            min_ele = min(min_ele, v[i]);
            max_ele = max(max_ele, v[i]);
        }
    }
    
    if(min_ele == INT_MAX) {
        return {-1,-1};
    }
    
    int left = 0;
    int right = n-1;
    
    while(left < n && v[left] <= min_ele) {
        left++;
    }
    
    while(right >= 0 && v[right] >= max_ele) {
        right--;
    }
    
    return {left, right};
}

int main() {
    vector<int> v = {1,2,3,4,5,8,6,7,9,10,11};
    pair<int, int> res = subarraySort(v);
    cout<<res.first<<" "<<res.second<<endl;
}