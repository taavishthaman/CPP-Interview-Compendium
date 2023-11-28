#include<iostream>
#include<vector>
using namespace std;

bool can_place(vector<vector<int>> & board, int r, int c, int num, int n) {
    //Check the row
    for(int col=0; col < n; col++) {
        if(board[r][col] == num) {
            return false;
        }
    }
    
    //Check the col
    for(int row=0; row < n; row++) {
        if(board[row][c] == num) {
            return false;
        }
    }
    
    //Check 3X3 submatrix
    int i = (r/3)*3;
    int j = (c/3)*3;
    
    for(int row=i; row<i+3; row++) {
        for(int col=j; col<j+3; col++) {
            if(board[row][col] == num) {
                return false;
            }
        }
    }
    
    return true;
}

bool solve_sudoku(vector<vector<int>> & board, int i, int j, int n) {
    if(i == n) {
        return true;
    }
    
    if(j == n) {
        return solve_sudoku(board, i+1, 0, n);
    }
    
    if(board[i][j] != 0) {
        return solve_sudoku(board, i, j+1, n);
    }
    
    for(int num=1; num<=9; num++) {
        if(can_place(board, i, j, num, n)) {
            board[i][j] = num;
            bool success = solve_sudoku(board, i, j+1, n);
            if(success) {
                return true;
            }
        }
    }
    
    board[i][j] = 0;
    return false;
}


int main() {
    int n = 9;
    vector<vector<int>> board = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    
    solve_sudoku(board, 0, 0, n);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}