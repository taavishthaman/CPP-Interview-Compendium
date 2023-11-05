#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> & arr, int key) {
    int lo = 0;
    int hi = arr.size()-1;
    int ans = -1;

    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(arr[mid] == key) {
            ans = mid;
            hi = mid - 1;
        } else if(key < arr[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
}

int upper_bound(vector<int> & arr, int key) {
    int lo = 0;
    int hi = arr.size()-1;
    int ans = -1;

    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(arr[mid] == key) {
            ans = mid;
            lo = mid + 1;
        } else if(key > arr[mid]) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {0,1,1,2,3,3,3,3,4,5,5,5,10};
    int l = lower_bound(arr, 3);
    int h = upper_bound(arr, 3);
    int count = h-l+1;
    cout<<count<<endl;
}