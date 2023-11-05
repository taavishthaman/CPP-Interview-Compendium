#include<bits/stdc++.h>
using namespace std;

int min_jumps(vector<int> & arr, int n, int idx) {
    if(idx >= n) {
        return INT_MAX;
    }
    
    if(idx == n-1) {
        return 0;
    }
    
    int res = INT_MAX;
    
    for(int jump=1; jump<=arr[idx]; jump++) {
        int subprob = min_jumps(arr, n, idx+jump);
        if(subprob != INT_MAX) {
            res = min(res, subprob + 1);
        }
    }
    
    return res;
}

int jumpsBU(vector<int> & arr, int n) {
    vector<int> dp(n, 0);
    
    for(int i=n-2; i>=0; i--) {
        int max_jump = arr[i];
        int res = INT_MAX;
        for(int j=1; j<=max_jump; j++) {
            int cjump = i + j;
            if(i+j < n) {
                res = min(dp[cjump], res);
            }
        }
        
        if(res == INT_MAX) {
            dp[i] = res;
        } else {
            dp[i] = res + 1;
        }
    }
    
    return dp[0];
}

int main() {
    vector<int> arr = {3,4,2,1,2,3,7,1,1,3};
    int n = arr.size();
    vector<int> dp(n, 0);
    cout<<min_jumps(arr, n, 0)<<endl;
    int res = jumpsBU(arr, n);
    cout<<res<<endl;
}