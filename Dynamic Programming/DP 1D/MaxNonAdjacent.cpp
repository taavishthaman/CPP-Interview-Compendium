#include<bits/stdc++.h>
using namespace std;

int maxNonAdjacent(vector<int> & arr, int n) {
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    
    for(int i=2; i<n; i++) {
        int opt1 = arr[i] + dp[i-2];
        int opt2 = dp[i-1];
        dp[i] = max(opt1, opt2);
    }
    
    return dp[n-1];
}

int main() {
    vector<int> arr = {6,10,12,7,9,14};
    int n = arr.size();
    cout<<maxNonAdjacent(arr, n)<<endl;
}