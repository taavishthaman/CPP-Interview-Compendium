#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

int min_swaps(vector<int> & v) {
    int n = v.size();
    
    vector<pair<int, int>> nv;
    
    for(int i=0; i<n; i++) {
        nv.push_back({v[i], i});
    }
    
    sort(nv.begin(), nv.end(), compare);
    
    vector<bool> visited(n, false);
    int total = 0;
    
    for(int i=0; i<n; i++) {
        if(visited[i] || v[i] == nv[i].first) {
            continue;
        }
        
        int cycles = 0;
        int node = i;
        while(!visited[node]) {
            visited[node] = true;
            node = nv[node].second;
            cycles ++;
        }
        
        total += cycles-1;
    }
    
    return total;
}

int main() {
    vector<int> v = {4,5,3,2,1};
    int n = v.size();
    cout<<min_swaps(v)<<endl;
}