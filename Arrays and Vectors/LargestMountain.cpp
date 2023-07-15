#include<bits/stdc++.h>
using namespace std;

int largest_mountain(vector<int> & arr) {
    int n = arr.size();
    
    int largest = 0;
    
    for(int i=1; i<n-1;) {
        //First find a peak element
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            int cnt = 1;
            int j = i;
            while(j > 0 && arr[j] > arr[j-1]) {
                j--;
                cnt++;
            }
            while(i < n-1 && arr[i] > arr[i+1]) {
                cnt++;
                i++;
            }
            largest = max(largest, cnt);
        }
        else {
            i++;
        }
    }
    
    return largest;
}

int main() {
    vector<int> v = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    int res = largest_mountain(v);
    cout<<res<<endl;
}