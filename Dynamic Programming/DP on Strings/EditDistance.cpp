#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int edRec(string & s1, string & s2, int i, int j) {
        if(i == s1.size() && j == s2.size()) {
            return 0;
        }

        if(i == s1.size()) {
            return s2.size() - j;
        }

        if(j == s2.size()) {
            return s1.size() - i;
        }

        if(s1[i] != s2[j]) {
            return min({edRec(s1, s2, i+1, j) + 1, edRec(s1, s2, i, j+1) + 1, edRec(s1, s2, i+1, j+1) + 1});
        } else {
            return edRec(s1, s2, i+1, j+1);
        }
    }

    int edTd(string & s1, string & s2, int i, int j, vector<vector<int>> & dp) {
        if(i == s1.size() && j == s2.size()) {
            return 0;
        }

        if(i == s1.size()) {
            return s2.size() - j;
        }

        if(j == s2.size()) {
            return s1.size() - i;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s1[i] != s2[j]) {
            return dp[i][j] = min({edTd(s1, s2, i+1, j, dp) + 1, edTd(s1, s2, i, j+1, dp) + 1, edTd(s1, s2, i+1, j+1, dp) + 1});
        } else {
            return dp[i][j] = edTd(s1, s2, i+1, j+1, dp);
        }
        //BC
        //DEF
    }

    int edBu(string s1, string s2) {
        int N = s1.size();
        int M = s2.size();

        vector<vector<int>> dp(N+1, vector<int>(M+1, 0));

        for(int i=1; i<=N; i++) {
            dp[i][0] = i;
        }

        for(int i=1; i<=M; i++) {
            dp[0][i] = i;
        }

        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                if(s1[i-1] != s2[j-1]) {
                    dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
                } else {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }

        return dp[N][M];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return edRec(word1, word2, 0, 0);
        //return edTd(word1, word2, 0, 0, dp);
        return edBu(word1, word2);
    }
};