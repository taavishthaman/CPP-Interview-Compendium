#include<bits/stdc++.h>
using namespace std;

int winesTD(vector<int> & prices, int L, int R, int y, vector<vector<int>> & dp) {
    if(L > R) {
        return 0;
    }
    
    if(dp[L][R] != 0) {
        return dp[L][R];
    }
    
    int left = y * prices[L] + winesTD(prices, L+1, R, y+1, dp);
    int right = y * prices[R] + winesTD(prices, L, R-1, y+1, dp);
    
    return dp[L][R] = max(left, right);
}

int winesBU(vector<int> & prices, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<n; j++) {
            if(i == j) {
                int year = n;
                dp[i][j] = year * prices[i];
            }
            else if(i < j) {
                int year = n - (j-i);
                int op1 = year * prices[i] + dp[i+1][j];
                int op2 = year * prices[j] + dp[i][j-1];
                dp[i][j] = max(op1, op2);
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return dp[0][n-1];
}

int main() {
    vector<int> prices = {2,3,5,1,4};
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    cout<<winesTD(prices, 0, n-1, 1, dp)<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<winesBU(prices, prices.size())<<endl;
}