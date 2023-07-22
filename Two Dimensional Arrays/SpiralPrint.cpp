#include<bits/stdc++.h>
using namespace std;

vector<int> spiralPrint(vector<vector<int>> & matrix) {
    vector<int> op;
    int n = matrix.size();
    int m = matrix[0].size();
    
    int sr = 0;
    int sc = 0;
    int er = n-1;
    int ec = m-1;
    
    while(sr <= er && sc <= ec) {
        
        for(int col=sc; col<=ec; col++) {
            op.push_back(matrix[sr][col]);
        }
        
        for(int row=sr+1; row<=er; row++) {
            op.push_back(matrix[row][ec]);
        }
        
        for(int col=ec-1; col>=sc; col--) {
            if(sr == er) {
                break;
            }
            op.push_back(matrix[er][col]);
        }
        
        for(int row=er-1; row>=sr+1; row--) {
            if(sc == ec) {
                break;
            }
            op.push_back(matrix[row][sc]);
        }
        
        sr++;
        sc++;
        er--;
        ec--;
    }
    
    return op;
}

int main() {
    vector<vector<int>> v = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };
    
    vector<int> op = spiralPrint(v);
    
    for(int num : op) {
        cout<<num<<", ";
    }
}