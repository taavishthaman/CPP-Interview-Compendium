#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> & c, vector<vector<int>> & visited, vector<int> & path, int i, int j, int n) {
    if(i == n-1 && j == n-1) {
        visited[i][j] = 1;
        path.push_back(n * i + j + 1);
        return true;
    }
    
    
    path.push_back(n * i + j + 1);
    visited[i][j] = 1;
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    for(int k=0; k<4; k++) {
        int ni = dy[k] + i;
        int nj = dx[k] + j;
        
        if(ni >= 0 && nj >= 0 && ni < n && nj < n && !visited[ni][nj] && c[ni][nj] != 'X') {
            bool success = dfs(c, visited, path, ni, nj, n);
            if(success) {
                return true;
            }
        }
    }
    
    path.pop_back();
    visited[i][j] = 0;
    
    return false;
}

vector<int> findPath(int n, vector<vector<char>> c){
    vector<vector<int>> visited(n, vector<int>(n ,0));
    vector<int> path;
    dfs(c, visited, path, 0, 0, n);
    return path;
}

int main() {
    vector<vector<char>> c = {
        {'O','O','X','O'},
        {'O','X','O','O'},
        {'O','O','O','X'},
        {'X','X','O','O'}
    };
    
    int n = 4;
    vector<int> p = findPath(n, c);
    
    for(int num : p) {
        cout<<num<<", ";
    }
}
