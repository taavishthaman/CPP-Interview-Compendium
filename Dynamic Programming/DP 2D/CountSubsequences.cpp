#include<bits/stdc++.h>
using namespace std;

int countSub(string a, string b, int m, int n) {
    if((m == -1 && n == -1) || n == -1) {
        return 1;
    }
    if(m == -1) {
        return 0;
    }
    
    if(a[m] == b[n]) {
        //Either match or don't match
        return countSub(a, b, m-1, n-1) + countSub(a, b, m-1, n);
    }
    
    return countSub(a, b, m-1, n);
}

int countSubBU(string a, string b) {
    int m = a.size();
    int n = b.size();
    
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    //First column should be 1, since if the second string is empty it exists once inside the bigger string
    for(int i=0; i<=m; i++) {
        dp[i][0] = 1;
    }
    
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    string a = "ABBCECDGCC";
    string b = "ABC";
    cout<<countSub(a, b, a.size()-1, b.size()-1)<<endl;
    cout<<countSubBU(a, b)<<endl;
}