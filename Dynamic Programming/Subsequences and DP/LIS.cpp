#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> & v) {
    int n = v.size();
    vector<int> dp(n, 1);
    int max_sub_len = 1;
    for(int i=0; i < n; i++) {
        for(int j=0; j<i; j++) {
            if(v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                max_sub_len = max(max_sub_len, dp[i]);
            }
        }
    }
    
    return max_sub_len;
}

int main() {
    vector<int> v = {7, 49, 23, 8, 30, 22, 44, 28, 23, 9, 40, 15};
    cout<<lis(v)<<endl;
}