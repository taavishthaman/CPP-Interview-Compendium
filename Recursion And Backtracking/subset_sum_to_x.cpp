#include<bits/stdc++.h>
using namespace std;

int find_subsets(vector<int> & v, int i, int sum) {
    if(i == v.size()) {
        if(sum == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    
    return find_subsets(v, i+1, sum-v[i]) + find_subsets(v, i+1, sum);
}

int main() {
    vector<int> v = {10,12,15,6,19,20};
    int sum = 16;
    cout<<find_subsets(v, 0, sum)<<endl;
}