#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5};
    int k = 10005;
    k = 10005 % v.size();
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin()+k);
    reverse(v.begin()+k, v.end());
    
    for(int num : v) {
        cout<<num<<",";
    }
}