#include<iostream>
#include<vector>
using namespace std;

int grid_path(int n, int m, int r, int c) {
    
    if(r == n-1 && c == m-1) {
        return 1;
    }
    
    if(r >= n || c >= m) {
        return 0;
    }
    
    return grid_path(n, m, r+1, c) + grid_path(n, m, r, c+1);
}

int main() {
    int n, m;
    cin>>n>>m;
    cout<<grid_path(n, m, 0, 0)<<endl;
}