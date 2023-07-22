#include<bits/stdc++.h>
using namespace std;

pair<int, int> staircaseSearch(vector<vector<int>> & matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    int r = 0;
    int c = m-1;
    
    while(r < n && c >= 0) {
        if(matrix[r][c] == target) {
            return {r, c};
        }
        else if(target < matrix[r][c]) {
            c--;
        }
        else {
            r++;
        }
    }
    
    return {-1,-1};
}

int main() {
    vector<vector<int>> matrix = {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}
    };
    
    pair<int, int> p = staircaseSearch(matrix, 37);
    cout<<p.first<<", "<<p.second<<endl;
}