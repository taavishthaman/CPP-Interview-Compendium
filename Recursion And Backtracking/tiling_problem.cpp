#include<iostream>
#include<vector>
using namespace std;

int tiling_problem(int n, int m) {
    if(n <= m-1) {
        return 1;
    }
    
    return tiling_problem(n-1, m) + tiling_problem(n-m, m);
}

int main() {
    int n, m;
    cin>>n>>m;
    cout<<tiling_problem(n,m)<<endl;
}

