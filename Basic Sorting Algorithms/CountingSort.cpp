#include<bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> & nums) {
    int n = nums.size();
    int max_num = INT_MIN;
    
    for(int i=0; i<n; i++) {
        max_num = max(nums[i], max_num);
    }
    
    vector<int> frq(max_num+1, 0);
    
    for(int num : nums) {
        frq[num]++;
    }
    
    n = frq.size();
    int idx = 0;
    for(int i=0; i<n; i++) {
        if(frq[i] > 0) {
            while(frq[i] > 0) {
                nums[idx] = i;
                frq[i]--;
                idx++;
            }
        }
    }
}

int main() {
    vector<int> v = {7,6,5,4,3,2,1,0,5,3,2,1,0,7,0};
    counting_sort(v);
    for(int num : v) {
        cout<<num<<" ";
    }
}