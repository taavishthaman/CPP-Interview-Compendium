#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> & nums) {
    int n = nums.size();
    vector<vector<int>> op;
    if(n < 3) {
        return op;
    }
    sort(nums.begin(), nums.end());

    for(int i=0; i<n-2; i++) {
        if(i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int start = i+1;
        int end = n-1;

        while(start < end) {
            int sum = nums[i] + nums[start] + nums[end];
            if(sum == 0) {
                vector<int> v = {nums[i], nums[start], nums[end]};
                op.push_back(v);
                start++;
                while(nums[start] == nums[start-1] && start < end) {
                    start++;
                }
            } else if(sum < 0) {
                start++;
            } else {
                end--;
            }
        }
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