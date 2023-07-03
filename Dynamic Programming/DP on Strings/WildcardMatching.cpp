#include<bits/stdc++.h>
using namespace std;

bool isMatch(string & s, string & p, int i, int j, vector<vector<int>> & dp) {
    if(i == s.size() && j == p.size()) {
        return true;
    }
    if(j == p.size()) {
        return false;
    }
    
    if(dp[i][j] != -1) {
        return true;
    }
    
    int ans = 0;
    if(i < s.size() && s[i] == p[j]) {
        ans |= isMatch(s, p, i+1, j+1, dp);
    }
    else if(p[j] == '?') {
        if(i == s.size()) {
            return false;
        } else {
            ans |= isMatch(s, p, i+1, j+1, dp);
        }
    }
    else if(p[j] == '*') {
        if(i < s.size()) {
            ans |= isMatch(s, p, i+1, j, dp);
        }
        ans |= isMatch(s, p, i, j+1, dp);
    }
    
    return dp[i][j] = ans;
}

bool wildcardMatching(string s, string p) {
    vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
    return isMatch(s, p, 0, 0, dp);
}

int main() {
    string s = "ho";
    string p = "h?o";
    cout<<wildcardMatching(s, p)<<endl;
}