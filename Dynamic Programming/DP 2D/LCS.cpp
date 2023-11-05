#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int i, int j) {
    if(i == s1.size() || j == s2.size()) {
        return 0;
    }
    
    char ch1 = s1[i];
    char ch2 = s2[j];
    
    if(ch1 == ch2) {
        return lcs(s1, s2, i+1, j+1) + 1;
    }
    
    return max(lcs(s1, s2, i+1, j), lcs(s1, s2, i, j+1));
}

int lcsTD(string s1, string s2, int i, int j, vector<vector<int>> & dp) {
    if(i == s1.size() || j == s2.size()) {
        return 0;
    }
    
    char ch1 = s1[i];
    char ch2 = s2[j];
    
    if(ch1 == ch2) {
        return dp[i][j] = lcsTD(s1, s2, i+1, j+1, dp) + 1;
    }
    
    return dp[i][j] = max(lcsTD(s1, s2, i+1, j, dp), lcsTD(s1, s2, i, j+1, dp));
}

int lcsBU(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    
    for(int i=1; i<=n1; i++) {
        for(int j=1; j<=n2; j++) {
            char ch1 = s1[i-1];
            char ch2 = s2[j-1];
            
            if(ch1 == ch2) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    string op = "";
    int i = n1;
    int j = n2;
    
    while(i != 0 && j != 0) {
        if(dp[i][j] == dp[i-1][j]) {
            i--;
        } else if(dp[i][j] == dp[i][j-1]) {
            j--;
        } else {
            op = s1[i-1] + op;
            i--;
            j--;
        }
    }
    
    cout<<op<<endl;
    
    return dp[n1][n2];
}

int main() {
    string s1 = "ABCD";
    string s2 = "ABEDG";
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout<<lcs(s1, s2, 0, 0)<<endl;
    cout<<lcsTD(s1, s2, 0, 0, dp)<<endl;
    cout<<lcsBU(s1, s2)<<endl;
}