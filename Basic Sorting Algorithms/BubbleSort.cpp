#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> & v) {
    int n = v.size();
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-1-i; j++) {
            if(v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
}

int main() {
    vector<int> v = {7,6,5,4,3,2,1};
    bubble_sort(v);
    for(int num : v) {
        cout<<num<<" ";
    }
}