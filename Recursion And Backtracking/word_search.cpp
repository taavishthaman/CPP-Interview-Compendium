#include<bits/stdc++.h>
using namespace std;

bool find_word(vector<vector<char>> &board, string & word, vector<vector<bool>> & visited, 
int i, int j, int idx, int n, int m) {
    if(idx == word.size() -1 && board[i][j] == word[idx]) {
        return true;
    }
    
    visited[i][j] = true;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    for(int k=0; k<4; k++) {
        int nx = dx[k] + j;
        int ny = dy[k] + i;
        
        if(nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[ny][nx] && board[ny][nx] == word[idx+1]) {
            bool success = find_word(board, word, visited, ny, nx, idx+1, n, m);
            if(success) {
                return true;
            }
        }
    }
    
    visited[i][j] = false;
    return false;
}

bool wordSearch(vector<vector<char>> &board, string word) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == word[0]) {
                bool success = find_word(board, word, visited, i, j, 0, n, m);
                if(success) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    
    string word = "ABCCED";
    cout<<wordSearch(board, word)<<endl;
}