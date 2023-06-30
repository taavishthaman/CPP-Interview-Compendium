#include<bits/stdc++.h>
using namespace std;

int friendsPairing(int n) {
    if(n <= 1) {
        return 1;
    }
    
    return friendsPairing(n-1) + (n-1) * friendsPairing(n-2);
}

int main() {
    int n;
    cin>>n;
    cout<<friendsPairing(n)<<endl;
}