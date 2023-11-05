#include<bits/stdc++.h>
using namespace std;

int frogMinCost(vector<int> & nums, int n) {
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = abs(nums[1] - nums[0]);
    
    for(int i=2; i<n; i++) {
        int cost1 = dp[i-2] + abs(nums[i-2] - nums[i]);
        int cost2 = dp[i-1] + abs(nums[i-1] - nums[i]);
        
        dp[i] = min(cost1, cost2);
    }
    
    return dp[n-1];
}

int main() {
    vector<int> nums = {10,30,40,30};
    int n = nums.size();
    cout<<frogMinCost(nums, n)<<endl;
}