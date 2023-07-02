class Solution {
public:
    int lcs(string & s1, string & s2, int i, int j, int n, int m, vector<vector<int>> & dp) {
        if(i == n || j == m) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if(s1[i] == s2[j]) {
            ans = 1 + lcs(s1, s2, i+1, j+1, n, m, dp);
        }
        else {
            ans = max(lcs(s1, s2, i+1, j, n, m, dp), lcs(s1, s2, i, j+1, n, m, dp));
        }

        return dp[i][j] = ans;
    }

    int lcs_bu(string s1, string s2) {
        int N = s1.size();
        int M = s2.size();

        vector<vector<int>> dp(N+1, vector<int>(M+1, 0));

        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[N][M];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return lcs(text1, text2, 0, 0, n, m, dp);
        return lcs_bu(text1, text2);
    }
};