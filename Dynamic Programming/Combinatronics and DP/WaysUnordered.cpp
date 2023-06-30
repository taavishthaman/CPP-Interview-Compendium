#include<bits/stdc++.h>
using namespace std;

int countUnordered(int n, int min) {
    if(n == 0) {
        return 1;
    }
    
    int ans = 0;
    for(int i=min; i<=n; i++) {
        ans += countUnordered(n-i, i);
    }
    
    return ans;
}

int countUnorderedBu(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            dp[j] += dp[j-i];
        }
    }
    
    return dp[n];
}

int main() {
    for(int i=1; i<=10; i++) {
        cout<<countUnordered(i, 1)<<endl;
        cout<<countUnorderedBu(i)<<endl;
    }
}