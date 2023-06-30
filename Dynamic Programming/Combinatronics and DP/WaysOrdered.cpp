#include<bits/stdc++.h>
using namespace std;

int countWaysOrdered(int n, vector<int> & dp) {
    if(n == 0) {
        return 1;
    }
    
    if(dp[n] != -1) {
        return dp[n];
    }
    
    int ans = 0;
    for(int count=1; count<=n; count++) {
        ans += countWaysOrdered(n-count, dp);
    }
    
    return dp[n] = ans;
}

int countWaysOrderedBu(int n) {
    vector<int> dp(n+1, 0);
    
    int sum = 0;
    for(int i=1; i<=n; i++) {
        dp[i] = sum+1;
        sum += dp[i];
    }
    
    return dp[n];
}

int countWaysOrderedMostEfficient(int n) {
    return pow(2, n-1);
}

int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout<<countWaysOrdered(n, dp)<<endl;
    cout<<countWaysOrderedBu(n)<<endl;
    cout<<countWaysOrderedMostEfficient(n)<<endl;
}