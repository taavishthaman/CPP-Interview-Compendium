#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> & arr, int target) {
    int lo = 0;
    int hi = arr.size() - 1;
    
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(arr[mid] == target) {
            return mid;
        }
        else if(target < arr[mid]) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    
    return -1;
}


int main() {
    vector<int> arr = {1,2,3,4,5,6,7};
    int index = binary_search(arr, 2);
    cout<<index<<endl;
}