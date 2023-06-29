#include<bits/stdc++.h>
using namespace std;

int tilingProblem(int n) {
    if(n == 1) {
        return 1;
    }
    
    if(n == 2) {
        return 3;
    }

    return tilingProblem(n-1) + 2 * tilingProblem(n-2);
}

int main() {
    //3 kinds of tiles...
    //1 X 2 [][]

    //2 X 1 []
    //      []

    //2 X 2 [][]
    //      [][]
    
    // [][][]
    // [][][]
    int n;
    cin>>n;

    cout<<tilingProblem(n)<<endl;
}
