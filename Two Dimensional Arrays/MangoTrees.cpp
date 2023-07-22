#include<bits/stdc++.h>
using namespace std;

int mangoTrees(vector<vector<char>> & v) {
    int n = v.size();
    int m = v[0].size();
    
    vector<vector<int>> prefix(n, vector<int>(m, 0));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i == 0 && j == 0) {
                if(v[i][j] == '#') {
                    prefix[i][j] = 1;
                } else {
                    prefix[i][j] = 0;
                }
            }
            else if(i == 0 && j > 0) {
                if(v[i][j] == '#') {
                    prefix[i][j] = prefix[i][j-1] + 1;
                }
                else {
                    prefix[i][j] = prefix[i][j-1];
                }
            }
            else if(j == 0 && i > 0) {
                if(v[i][j] == '#') {
                    prefix[i][j] = prefix[i-1][j] + 1;
                }
                else {
                    prefix[i][j] = prefix[i-1][j];
                }
            }
            else {
                int s1 = prefix[i-1][j];
                int s2 = prefix[i][j-1];
                int s3 = prefix[i-1][j-1];
                
                int res = s1 + s2 - s3;
                if(v[i][j] == '#') {
                    res += 1;
                }
                prefix[i][j] = res;
            }
        }
    }
    
    //Maximize the minimum division of the field
    int max_trees = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int tl = prefix[i][j];
            int tr = prefix[i][m-1] - tl;
            int bl = prefix[n-1][j] - tl;
            int br = prefix[n-1][m-1] - tl - tr - bl;
            
            max_trees = max(max_trees, min({tl, tr, bl, br}));
        }
    }
    
    return max_trees;
}

int main() {
    vector<vector<char>> v = {
        {'.','#','#','.','.','.'},
        {'#','.','.','#','#','.'},
        {'.','#','.','.','.','.'},
        {'.','#','#','.','.','#'},
        {'#','.','.','#','#','.'},
        {'.','#','.','.','.','.'}
    };
    
    int res = mangoTrees(v);
    cout<<res<<endl;
}