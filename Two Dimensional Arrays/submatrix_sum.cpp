#include<bits/stdc++.h>
using namespace std;

int sum(vector<vector<int>> v, int sr, int sc, int er, int ec){
    int n = v.size();
    int m = v[0].size();
    
    vector<vector<int>> prefix(n, vector<int>(m, 0));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i == 0 && j == 0) {
                prefix[i][j] = v[i][j];
            } else if(i == 0) {
                prefix[i][j] = prefix[i][j-1] + v[i][j];
            } else if(j == 0) {
                prefix[i][j] = prefix[i-1][j] + v[i][j];
            } else {
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + v[i][j];
            }
        }
    }
    
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    
    if(sr > 0 && sc > 0)
        s1 = prefix[sr-1][sc-1];
    if(sc > 0)
        s2 = prefix[er][sc-1];
    if(sr > 0)
        s3 = prefix[sr-1][ec];
        
    s4 = prefix[er][ec];
    
    int res = s4 - s2 - s3 + s1;
    return res;
}

int main() {

    vector<vector<int>> v = {
        {1,2,3,4,6},
        {5,3,8,1,2},
        {4,6,7,5,5},
        {2,4,8,9,4}
    };
    
    int res = sum(v,1,2,3,3);
    cout<<res<<endl;
}