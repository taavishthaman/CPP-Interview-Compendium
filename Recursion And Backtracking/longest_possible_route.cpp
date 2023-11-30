#include<bits/stdc++.h>
using namespace std;

void longest_path(vector<vector<int>> v, int path, int * max_path, vector<vector<int>> & visited, 
int i, int j, int n, int m) {
    if(i == n-1 && j == m-1) {
        *max_path = max(path, *max_path);
        return;
    }
    
    visited[i][j] = true;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    for(int k=0; k<4; k++) {
        int ni = i + dy[k];
        int nj = j + dx[k];
        
        if(ni >= 0 && nj >= 0 && ni < n && nj < m && !visited[ni][nj] && v[ni][nj] != 0) {
            longest_path(v, path+1, max_path, visited, ni, nj, n, m);
        }
    }
    
    visited[i][j] = false;
}

int findLongestPath(int m, int n, vector<vector<int>> v){
    swap(m, n);
    int max_path = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    longest_path(v, 0, &max_path, visited, 0, 0, n, m);
    return max_path;
}

int main() {
    vector<vector<int>> v = {
        {1,1,1},
        {1,1,1},
        {0,0,1}
    };
    
    int n = v.size();
    int m = v[0].size();
    
    int res = findLongestPath(m, n, v);
    cout<<res<<endl;
}
