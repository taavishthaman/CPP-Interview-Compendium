#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> housing(vector<int> & v, int target) {
    int i = 0;
    int n = v.size();
    int sum = 0;
    vector<pair<int, int>> op;
    for(int j=0; j<n; j++) {
        sum += v[j];
        if(sum > target){
            while(sum > target) {
                sum -= v[i];
                i++;
            }
        }
        
        if(sum == target) {
            pair<int, int> p = {i, j};
            op.push_back(p);
        } 
    }
    
    return op;
}

int main() {
    vector<int> v = {1,3,2,1,4,1,3,2,1,1,2};
    vector<pair<int, int>> op = housing(v, 8);
    for(auto p : op) {
        cout<<p.first<<", "<<p.second<<endl;
    }
}