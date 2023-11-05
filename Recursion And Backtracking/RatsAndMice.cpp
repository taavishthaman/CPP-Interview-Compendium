#include<bits/stdc++.h>
using namespace std;

bool findPath(vector<string> & v, int r, int c, int N, int M, vector<vector<bool>> & visited) {
    if(r == N-1 && c == M-1) {
        visited[r][c] = true;
        return true;
    }
    
    visited[r][c] = true;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool ans = false;
    for(int k=0; k<4; k++) {
        int nx = c + dx[k];
        int ny = r + dy[k];
        if(nx >= 0 && nx < M && ny >= 0 && ny < N && v[ny][nx] != 'X' && !visited[ny][nx]) {
            ans = findPath(v, ny, nx, N, M, visited);
            if(ans == true) {
                return true;
            }
        }
    }
    
    visited[r][c] = false;
    
    return ans;
}

int main() {
    vector<string> v = {"OXOO", "OOOX", "XOXO", "XOOX", "XXOO"};
    int N=5, M=4;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    findPath(v, 0, 0, N, M, visited);
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout<<visited[i][j]<<", ";
        }
        cout<<endl;
    }
}