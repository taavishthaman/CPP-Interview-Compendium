#include<bits/stdc++.h>
using namespace std;

vector<int> productArray(vector<int> arr){
    int n = arr.size();
    vector<int> op(n, 0);
    op[0] = arr[0];
    for(int i=1; i<n; i++) {
        op[i] = op[i-1] * arr[i];
    }
    
    int product = 1;
    
    for(int i=n-1; i>=1; i--) {
        op[i] = op[i-1] * product;
        product = product * arr[i];
    }
    op[0] = product;
    return op;
}

int main() {
    vector<int> v = {1,2,3,4,5};
    vector<int> op = productArray(v);
    
    for(int num : op) {
        cout<<num<<" ";
    }
}