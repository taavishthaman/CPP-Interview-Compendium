#include<bits/stdc++.h>
using namespace std;

int countTrees(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    
    int ans = 0;
    for(int i=1; i<=n; i++) {
        ans += countTrees(i-1) * countTrees(n-i);
    }
    
    return ans;
}

int countTreesTD(int n, vector<int> & dp) {
    if(n == 0 || n == 1) {
        return 1;
    }
    
    if(dp[n] != 0) {
        return dp[n];
    }
    
    int ans = 0;
    for(int i=1; i<=n; i++) {
        ans += countTreesTD(i-1, dp) * countTreesTD(n-i, dp);
    }
    
    return dp[n] = ans;
}

int countTreesBU(int N) {
    vector<int> dp(N+1, 0);
    dp[0] = dp[1] = 1;
    
    for(int n=2; n<=N; n++) {
        for(int i=1; i<=n; i++) {
            dp[n] += dp[i-1] * dp[n-i];
        }
    }
    
    return dp[N];
}

int main() {
    int n = 4;
    vector<int> dp(n, 0);
    cout<<countTrees(n)<<endl;
    cout<<countTreesTD(n, dp)<<endl;
    cout<<countTrees(n)<<endl;
}