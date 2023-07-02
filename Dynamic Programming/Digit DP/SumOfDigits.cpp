#include<bits/stdc++.h>
using namespace std;

int addNumbers(string & s, int i, int sum, bool last, vector<vector<vector<int>>> & dp) {
    if(i == s.size()) {
        return sum;
    }
    
    if(dp[i][last][sum] != -1) {
        return dp[i][last][sum];
    }
    
    int till = last ? s[i]-'0' : 9;
    int ans = 0;
    for(int digit=0; digit<=till; digit++) {
        ans += addNumbers(s, i+1, sum+digit, last && (digit == till), dp);
    }
    return dp[i][last][sum] = ans;
}

int main() {
    int n1 = 100;
    int n2 = 777;
    string s1 = to_string(n1);
    string s2 = to_string(n2);
    //90 because max number can be 9999999999 and the sum of all digits would be 90
    vector<vector<vector<int>>> dp1(s1.size()+1, vector<vector<int>>(2, vector<int>(90, -1)));
    vector<vector<vector<int>>> dp2(s1.size()+1, vector<vector<int>>(2, vector<int>(90, -1)));
    int res1 = addNumbers(s1, 0, 0, true, dp1);
    int res2 = addNumbers(s2, 0, 0, true, dp2);
    int res = res2 - res1 + 1;
    cout<<res<<endl;
}