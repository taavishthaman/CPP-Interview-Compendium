#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> & nums) {
    int n = nums.size();
    
    for(int i=1; i<n; i++) {
        int curr = nums[i];
        int j = i-1;
        
        while(j >= 0 && nums[j] > curr) {
            nums[j+1] = nums[j];
            j--;
        }
        

        nums[j+1] = curr;
    }
}

int main() {
    vector<int> v = {7,6,5,4,3,2,1};
    insertion_sort(v);
    for(int num : v) {
        cout<<num<<" ";
    }
}