#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> & arr, int target) {
    int n = arr.size();
    int lo = 0;
    int hi = n-1;
    int ans = -1;
    
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(arr[mid] <= target) {
            ans = arr[mid];
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    
    return ans;
}

int main() {
    vector<int> v = {-1, -1, 2, 3, 5};
    cout<<lowerBound(v, 4)<<endl;
}