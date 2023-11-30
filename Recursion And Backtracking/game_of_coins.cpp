#include <bits/stdc++.h>
using namespace std;

int find_max_value(vector<int> & v, int l, int r, int n) {
    if(l > r) {
        return 0;
    }
    
    //Assume the worst when henry picks up the coin, hence we use min function
    int pick_left = v[l] + min(find_max_value(v, l+2, r, n), find_max_value(v, l, r-1, n));
    int pick_right = v[r] + min(find_max_value(v, l+1, r, n), find_max_value(v, l, r-2, n));
    
    return max(pick_left, pick_right);
}

int MaxValue(int n, vector<int> v){
    int l = 0;
    int r = n - 1;
    
    return find_max_value(v, l, r, n);
}

int main() {
    vector<int> v = {1,2,3,4};
    int n = 4;
    int res = MaxValue(n, v);
    cout<<res<<endl;
}