#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> & nums) {
    vector<vector<int>> op;
    set<vector<int>> s;
    
    sort(nums.begin(), nums.end());
    
    int n = nums.size();
    
    for(int i=0; i<n-2; i++) {
        if(nums[i] == nums[i-1]) {
            continue;
        }
        
        int start = i+1;
        int end = n-1;
        
        while(start < end) {
            int sum = nums[i] + nums[start] + nums[end];
            if(sum == 0) {
                vector<int> v = {nums[i], nums[start], nums[end]};
                s.insert(v);
                start++;
                end--;
            }
            else if(sum < 0) {
                start++;
            }
            else {
                end--;
            }
        }
    }
    
    for(vector<int> v : s) {
        op.push_back(v);
    }
    
    return op;
}

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> op = threeSum(nums);
    
    int n = op.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cout<<op[i][j]<<", ";   
        }
        cout<<endl;
    }
}