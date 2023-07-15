#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> & nums, int target) {
    int n = nums.size();
    vector<int> op;
    unordered_map<int, int> m;
    for(int i=0; i<n; i++) {
        if(m.find(target - nums[i]) != m.end()) {
            op.push_back(m[target-nums[i]]);
            op.push_back(i);
            return op;
        }
        m[nums[i]] = i;
    }
    
    return op;
}

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> op = twoSum(nums, target);
    cout<<op[0]<<" "<<op[1]<<endl;
}