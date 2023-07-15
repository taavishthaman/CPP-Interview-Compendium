#include<bits/stdc++.h>
using namespace std;

int linear_search(vector<int> & arr, int target) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    vector<int> arr = {2,3,4,1,6,7,5};
    int index = linear_search(arr, 4);
    cout<<index<<endl;
}