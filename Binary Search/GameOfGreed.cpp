#include<bits/stdc++.h>
using namespace std;

int canDivideAmongK(vector<int> & arr, int k, int amount) {
    int curr_amount = 0;
    int friends = 0;
    
    for(int i=0; i<arr.size(); i++) {
        if(curr_amount + arr[i] >= amount) {
            friends++;
            curr_amount = 0;
        } else {
            curr_amount += arr[i];
        }
    }
    
    return friends >= k;
}

int kPartition(vector<int> & arr, int k) {
    int n = arr.size();
    int s = 0, e = 0;
    for(int num : arr) {
        e += num;
    }
    
    int res;
    while(s <= e) {
        int mid = (s + e) / 2;
        bool canDivide = canDivideAmongK(arr, k, mid);
        if(canDivide) {
            res = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    
    return res;
}

int main() {
    vector<int> arr = {10,20,40,30};
    int res = kPartition(arr, 3);
    cout<<res<<endl;
}