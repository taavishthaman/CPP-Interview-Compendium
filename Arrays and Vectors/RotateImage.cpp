#include<bits/stdc++.h>
using namespace std;

void rotateImage(vector<vector<int>> & matrix) {
    int n = matrix.size();
    
    //First do a transpose
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i >= j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    //Now do a coumnwise swapping
    for(int i=0; i<n/2; i++) {
        for(int j=0; j<n; j++) {
            swap(matrix[j][i], matrix[j][n-1-i]);
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    vector<vector<int>> image = {
        {1, 2, 3, 4, 5 },
        {6, 7, 8, 9, 10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    
    rotateImage(image);
}