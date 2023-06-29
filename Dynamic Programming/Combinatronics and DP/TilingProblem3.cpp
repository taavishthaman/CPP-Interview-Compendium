#include<bits/stdc++.h>
using namespace std;

int tilingProblem3(int n) {
    vector<int> f(n+1, 0);
    vector<int> g(n+1, 0);

    f[1] = 1;
    g[1] = 1;
    f[2] = 2;
    g[2] = 2;

    for(int i=3; i<=n; i++) {
        f[i] = f[i-1] + f[i-2] + 2 * g[i-2];
        g[i] = g[i-1] + f[i-1];
    }

    return f[n];
}

int main() {
    //  1 X 2 Tile [][]
    //  L shaped Tile []
    //                [][] which can be rotated

    //f(n) = f(n-1) + f(n-2) + 2 * g(n-2)
    //g(n) = g(n-1) + f(n-1)

    int n;
    cin>>n;
    cout<<tilingProblem3(n)<<endl;
}