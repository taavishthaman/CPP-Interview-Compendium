#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> & arr, int n) {
    vector<int> dp(n, 1);
    int largest = 1;
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j]+1);
                largest = max(largest, dp[i]);
            }
        }
    }
    
    return largest;
}

int main() {
    vector<int> v = {50,4,10,8,30,100};
    int n = v.size();
    cout<<lis(v, n)<<endl;
}