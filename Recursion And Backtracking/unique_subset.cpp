#include<bits/stdc++.h>
using namespace std;

void find_subsets(vector<int> & nums, vector<int> v, int i, vector<vector<int>> & res) {
    if(i == nums.size()) {
        res.push_back(v);
        return;
    }
    
    v.push_back(nums[i]);
    find_subsets(nums, v, i+1, res);
    v.pop_back();
    find_subsets(nums, v, i+1, res);
}


vector<vector<int>> uniqueSubsets(vector<int> nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> v;
    find_subsets(nums, v, 0, res);
    
    //Filter out duplicates
    set<vector<int>> s;
    for(auto v : res) {
        s.insert(v);
    }
    
    //Create an op vector
    vector<vector<int>> op;
    for(auto v : s) {
        op.push_back(v);
    }
    
    return op;
}

int main() {
    vector<int> nums = {4,1,0};
    vector<vector<int>> op = uniqueSubsets(nums);
    for(int i=0; i<op.size(); i++) {
        for(int num : op[i]) {
            cout<<num<<", ";
        }
        cout<<endl;
    }
}