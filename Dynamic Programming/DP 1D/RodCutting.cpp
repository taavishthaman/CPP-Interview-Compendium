#include<bits/stdc++.h>
using namespace std;

int rod_cutting(vector<int> & prices, int N) {
    if(N == 0) {
        return 0;
    }
    
    int ans = 0;
    
    for(int i=0; i<N; i++) {
        int cut = i+1;
        int current_ans = prices[i] + rod_cutting(prices, N-cut);
        
        ans = max(current_ans, ans);
    }
    
    return ans;
}

int rod_cutting_dp(vector<int> & prices, int N) {
    vector<int> dp(N+1, 0);
    
    for(int len=1; len<=N; len++) {
        int ans = INT_MIN;
        for(int i=0; i<len; i++) {
            int cut = i+1;
            int current_ans = prices[i] + dp[len-cut];
            ans = max(current_ans, ans);
        }
        
        dp[len] = ans;
    }
    
    return dp[N];
}

int main() {
    vector<int> prices = {3,5,8,9,10,17,17,20};
    int N = prices.size();
    
    cout<<rod_cutting(prices, N)<<endl;
    cout<<rod_cutting_dp(prices, N)<<endl;
}