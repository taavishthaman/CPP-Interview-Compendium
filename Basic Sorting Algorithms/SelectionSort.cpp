#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> & nums) {
    int n = nums.size();
    
    for(int i=0; i<n; i++) {
        int min_idx = i;
        for(int j=i+1; j<n; j++) {
            if(nums[j] < nums[min_idx]) {
                min_idx = j;
            }
        }
        
        swap(nums[i], nums[min_idx]);
    }
}

int main() {
    vector<int> v = {7,6,5,4,3,2,1};
    selection_sort(v);
    for(int num : v) {
        cout<<num<<" ";
    }
}