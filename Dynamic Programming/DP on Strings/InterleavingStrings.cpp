class Solution {
public:
    string s1, s2, s3;
    bool checkInterleave(int i, int j, int k, vector<vector<int>> & dp) {
        if(i == s1.size() && j == s2.size()) {
            return true;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if(s1[i] == s3[k]) {
            ans |= checkInterleave(i+1, j, k+1, dp);
        }
        if(s2[j] == s3[k]) {
            ans |= checkInterleave(i, j+1, k+1, dp);
        }

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size() + 1, -1));
        return checkInterleave(0, 0, 0, dp);
    }
};