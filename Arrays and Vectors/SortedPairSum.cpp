#include<bits/stdc++.h>
using namespace std;

pair<int, int> sortedPairSum(vector<int> & v, int target) {
    int n = v.size();
    int i = 0;
    int j = n-1;
    int min_abs_diff = INT_MAX;
    pair<int, int> res;
    while(i < j) {
        int sum = v[i] + v[j];
        int abs_diff = abs(sum - target);
        if(abs_diff < min_abs_diff) {
            min_abs_diff = abs_diff;
            res.first = v[i];
            res.second = v[j];
        }
        
        if(sum < target) {
            i++;
        }
        else {
            j--;
        }
    }
    
    return res;
}

int main() {
    vector<int> v = {10, 22, 28, 29, 30, 40};
    int target = 54;
    
    pair<int, int> p = sortedPairSum(v, target);
    cout<<p.first<<", "<<p.second<<endl;
}