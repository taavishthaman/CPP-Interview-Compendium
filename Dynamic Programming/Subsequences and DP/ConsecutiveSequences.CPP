#include<bits/stdc++.h>
using namespace std;

int longest_sequence(vector<int> & v, vector<int> & op) {
    int n = v.size();
    //First element be the index, and the second sequence length
    unordered_map<int, pair<int, int>> dp;
    int max_len = 1;
    int li;
    int le;
    for(int i=0; i<n; i++) {
        dp[v[i]] = {i+1, dp[v[i]-1].second + 1};
        // max_len = max(max_len, dp[v[i]].second);
        if(dp[v[i]].second > max_len) {
            max_len = dp[v[i]].second;
            li = i+1;
            le = v[i];
        }
    }
    
    while(true) {
        if(dp.find(le) != dp.end()) {
            op.insert(op.begin(), dp[le].first);
            le--;
        } else {
            break;
        }
    }
    
    return max_len;
}

int main() {
    vector<int> v = {6, 7, 8, 3, 4, 5, 9, 10, 11};
    vector<int> op;
    cout<<longest_sequence(v, op)<<endl;
    for(int num : op) {
        cout<<num<<" ";
    }
}