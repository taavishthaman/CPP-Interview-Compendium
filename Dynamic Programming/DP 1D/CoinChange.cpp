#include<bits/stdc++.h>
using namespace std;

int min_coins_td(vector<int> & coins, int amount, vector<int> & dp) {
    
    if(amount == 0) {
        return 0;
    }

    if(dp[amount] != 0) {
        return dp[amount];
    }

    int res = INT_MAX;

    for(int c : coins) {
        if(amount - c >= 0) {
            res = min(res, min_coins_td(coins, amount-c, dp));
        } 
    }

    if(res == INT_MAX) return INT_MAX;

    return dp[amount] = 1 + res;
}

int coin_change_bu(vector<int> & denoms, int amount) {
    vector<int> dp(amount+1, 0);

    for(int i=1; i<=amount; i++) {
        dp[i] = INT_MAX;
        
        for(int c : denoms) {
            if(i-c >= 0 && dp[i-c] != INT_MAX) {
                dp[i] = min(dp[i-c]+1, dp[i]);
            }
        }
    }
    
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int amount = 16;
    vector<int> coins = {1,5,7,10};
    vector<int> dp(amount + 1, 0);
    
    cout<<min_coins_td(coins, amount, dp)<<endl;
    cout<<coin_change_bu(coins, amount)<<endl;
}