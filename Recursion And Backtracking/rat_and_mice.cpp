#include<bits/stdc++.h>
using namespace std;

bool find_path(vector<string> & arr, vector<vector<int>> & visited, int i, int j, int n, int m) {
    if(i == n-1 && j == m-1) {
        visited[i][j] = 1;
        return true;
    }
    
    visited[i][j] = 1;
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    for(int k=0; k<4; k++) {
        int nx = j + dx[k];
        int ny = i + dy[k];
        
        if(nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[ny][nx] && arr[ny][nx] == 'O') {
            bool success = find_path(arr, visited, ny, nx, n, m);
            if(success) {
                return true;
            }
        }
    }
    
    visited[i][j] = 0;
    return false;
}

vector<vector<int>> ratAndMice(vector<string> arr) {
    int n = arr.size();
    int m = arr[0].size();
    
    vector<vector<int>> visited(n, vector<int>(m, 0));
    
    find_path(arr, visited, 0, 0, n, m);
    return visited;
}

int main() {
    vector<string> arr = {
        "OXOO",
        "OOOX",
        "XOXO",
        "XOOX",
        "XXOO"
    };
    
    vector<vector<int>> path = ratAndMice(arr);
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[0].size(); j++) {
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }

}