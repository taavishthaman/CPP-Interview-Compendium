#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> & arr) {
    int n = arr.size();
    
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    
    int max_sub = dp[0];
    for(int i=1; i<n; i++) {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        max_sub = max(dp[i], max_sub);
    }
    
    return max_sub;
}

int main() {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubarraySum(arr)<<endl;
}