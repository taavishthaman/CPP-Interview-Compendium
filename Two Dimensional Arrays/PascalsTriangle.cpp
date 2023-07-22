#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> op;
    
    for(int i=0; i<n; i++) {
        vector<int> v;
        for(int j=0; j<=i; j++) {
            if(j == 0 || j == i) {
                v.push_back(1);
            }
            else {
                int num1 = op[i-1][j];
                int num2 = op[i-1][j-1];
                v.push_back(num1 + num2);
            }
        }
        op.push_back(v);
    }
    
    return op;
}

int main() {
    int n;
    cin>>n;
    
    vector<vector<int>> op = pascalTriangle(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<op[i].size(); j++) {
            cout<<op[i][j]<<" ";
        }
        cout<<endl;
    }
}