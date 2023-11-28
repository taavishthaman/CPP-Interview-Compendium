#include<iostream>
#include<vector>
using namespace std;

void print_board(vector<vector<int>> & board, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool can_place(vector<vector<int>> & board, int row, int col, int n) {
    int r = row-1;
    int c = col-1;
    
    while(r >= 0 && c >= 0) {
        if(board[r][c] == 1) {
            return false;
        }
        r--;
        c--;
    }
    
    r = row-1;
    c = col;
    
    while(r >= 0) {
        if(board[r][c] == 1) {
            return false;
        }
        r--;
    }
    
    r = row-1;
    c = col+1;
    
    while(r >= 0 && c < n) {
        if(board[r][c] == 1) {
            return false;
        }
        r--;
        c++;
    }
    
    return true;
}

int solve_n_queens(vector<vector<int>> & board, int n, int i) {
    if(i == n) {
        print_board(board, n);
        return 1;
    }
    
    int ans = 0;
    for(int j=0; j<n; j++) {
        if(can_place(board, i, j, n)) {
            board[i][j] = 1;
            ans += solve_n_queens(board, n, i+1);
            board[i][j] = 0;
        }
    }
    
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int res = solve_n_queens(board, n, 0);
    cout<<res<<endl;
}