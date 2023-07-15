#include<bits/stdc++.h>
using namespace std;

void printPairs(vector<int> & arr) {
    int n = arr.size();
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            cout<<arr[i]<<" "<<arr[j]
        }
    }
}

int main() {
    vector<int> arr = {10, 20, 15, 35, 89, 69, 50};
    printPairs(arr);
}