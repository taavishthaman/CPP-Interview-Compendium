#include<bits/stdc++.h>
using namespace std;

int tilingProblem4(int n) {
    vector<int> f(n+1, 0);
    vector<int> g(n+1, 0);
    
    f[0] = g[0] = 1;
    f[1] = g[1] = 0;
    
    for(int i=2; i<=n; i++) {
        f[i] = f[i-2] + 2 * g[i-2];
        g[i] = g[i-2] + f[i];
    }
    
    return f[n];
}

int main() {
    int n;
    cin>>n;
    cout<<tilingProblem4(n)<<endl;
}