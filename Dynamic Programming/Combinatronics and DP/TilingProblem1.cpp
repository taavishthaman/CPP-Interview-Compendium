#include<bits/stdc++.h>
using namespace std;

int tilingProblem(int n, int m) {
    if(n <= m-1) {
        return 1;
    }

    return tilingProblem(n-1, m) + tilingProblem(n-m, m);
}

int main() {
    // For tiling problems, try to fill the first column in as many ways as possible 
    // and that will derive the recursive definitions
    int n;
    int m;
    cin>>n>>m;

    if(m > n) {
        return 0;
    }

    cout<<tilingProblem(n, m)<<endl;
    return 0;
}