#include<bits/stdc++.h>
using namespace std;

int defkin(vector<pair<int, int>> & v, int W, int H) {
    vector<int> x;
    vector<int> y;
    int n = v.size();
    x.push_back(0);
    y.push_back(0);
    
    for(int i=0; i<n; i++) {
        x.push_back(v[i].first);
        y.push_back(v[i].second);
    }
    
    x.push_back(W+1);
    y.push_back(H+1);
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    int x_diff = 0;
    int y_diff = 0;
    
    for(int i=0; i<x.size()-1; i++) {
        int diff = x[i+1] - x[i];
        x_diff = max(x_diff, diff);
    }
    
    for(int i=0; i<y.size()-1; i++) {
        int diff = y[i+1] - y[i];
        y_diff = max(y_diff, diff);
    }
    
    return (x_diff-1) * (y_diff-1);
}

int main() {
    vector<pair<int, int>> v = {{3,8}, {11,2}, {8,6}};
    int W = 15;
    int H = 8;
    cout<<defkin(v, W, H)<<endl;
}