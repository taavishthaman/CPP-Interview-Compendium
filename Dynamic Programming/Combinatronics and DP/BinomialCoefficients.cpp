#include<bits/stdc++.h>
using namespace std;

int pascalTriangle(int n, int r) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    dp[0][0] = 1;
    
    int row = 1;
    int col = 2;
    for(int r=row; r<=n; r++) {
        for(int c=0; c<col; c++) {
            if(c == 0 || c == col-1) {
                dp[r][c] = 1;
            } else {
                dp[r][c] = dp[r-1][c-1] + dp[r-1][c];
            }
        }
        col++;
    }
    
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return dp[n][r];
}

int main() {
    int n;
    int k;
    cin>>n>>k;
    cout<<pascalTriangle(n, k)<<endl;
}