#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> & prices, vector<int> & wts, int W, int N) {
    if(N == 0 || W == 0) {
        return 0;
    }
    
    int inc = 0, exc = 0;
    
    if(W-wts[N-1] >= 0) {
        inc = prices[N-1] + knapsack(prices, wts, W-wts[N-1], N-1);
    }
    exc = knapsack(prices, wts, W, N-1);
    
    return max(inc, exc);
}

int knapsackBU(vector<int> & prices, vector<int> & wts, int W, int N) {
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    
    for(int n=1; n<=N; n++) {
        for(int w=1; w<=W; w++) {
            int inc = 0, exc = 0;
            if(w - wts[n-1] >= 0) {
                inc = prices[n-1] + dp[n-1][w-wts[n-1]];
            }
            exc = dp[n-1][w];
            dp[n][w] = max(inc, exc);
        }
    }
    
    return dp[N][W];
}

int main() {
    vector<int> prices = {5,20,20,10};
    vector<int> wts = {2,7,3,4};
    int W = 11;
    int N = 4;
    cout<<knapsack(prices, wts, W, N)<<endl;
    cout<<knapsackBU(prices, wts, W, N)<<endl;
}