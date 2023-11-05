#include<bits/stdc++.h>
using namespace std;

int NKLadders(int N, int k) {
    if(N < 0) {
        return 0;
    }
    if(N == 0) {
        return 1;
    }
    
    int ans = 0;
    for(int i=1; i<=k; i++) {
        ans += NKLadders(N-i, k);
    }
    
    return ans;
}

int NKLaddersTD(int N, int k, vector<int> & dp) {
    if(N < 0) {
        return 0;
    }
    
    if(N == 0) {
        return 1;
    }
    
    if(dp[N] != 0) {
        return dp[N];
    }
    
    int ans = 0;
    
    for(int i=1; i<=k; i++) {
        ans += NKLaddersTD(N-i, k, dp);
    }
    
    return dp[N] = ans;
}

int NKLaddersBU(int N, int k) {
    vector<int> dp(N+1, 0);
    dp[0] = dp[1] = 1;
    
    for(int i=2; i<=N; i++) {
        int sum = 0;
        for(int j=1; j<=k; j++) {
            if(i-j >= 0)
                sum += dp[i-j];
        }
        dp[i] = sum;
    }
    
    return dp[N];
}

int NKLaddersBUOpt(int N, int k) {
    vector<int> dp(N+1, 0);
    dp[0] = dp[1] = 1;
    
    for(int i=2; i<=k; i++) {
        dp[i] = 2 * dp[i-1];
    }
    
    for(int i=k+1; i<=N; i++) {
        dp[i] = 2 * dp[i-1] - dp[i-k-1];
    }
    
    return dp[N];
}

int main() {
    int N = 6;
    int k = 4;
    vector<int> dp(N+1, 0);
    cout<<NKLadders(N, k)<<endl;
    cout<<NKLaddersTD(N, k, dp)<<endl;
    cout<<NKLaddersBU(N, k)<<endl;
    cout<<NKLaddersBUOpt(N, k)<<endl;
}