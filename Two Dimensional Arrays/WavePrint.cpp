#include<bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> & v) {
    int n = v.size();
    int m = v[0].size();
    vector<int> op;
    int j = m-1;
    bool reverse = false;
    while(j >= 0) {
        if(reverse) {
            for(int i=n-1; i>=0; i--) {
                op.push_back(v[i][j]);
            }
        }
        else {
            for(int i=0; i<n; i++) {
                op.push_back(v[i][j]);
            }
        }
        j--;
        reverse = !reverse;
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
    
    vector<int> res = wavePrint(v);
    
    for(int num : res) {
        cout<<num<<", ";
    }
}