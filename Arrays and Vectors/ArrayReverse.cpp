#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,2,3,4,5,6,7};
    int len = arr.size();
    for(int i=0; i<len/2; i++) {
        swap(arr[i], arr[len-1-i]);
    }
    
    for(int i=0; i<len; i++) {
        cout<<arr[i]<<",";
    }
}