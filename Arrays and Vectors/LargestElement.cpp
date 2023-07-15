#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int> & arr) {
    int n = arr.size();
    int largest = arr[0];
    
    for(int i=1; i<n; i++) {
        largest = max(arr[i], largest);
    }
    
    return largest;
}

int main() {
    vector<int> arr = {10, 20, 15, 35, 89, 69, 50};
    cout<<largestElement(arr)<<endl;
}