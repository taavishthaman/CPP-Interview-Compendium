#include<bits/stdc++.h>
using namespace std;

int climbing_ladders(int n) {
    //Exclude calls on negative indices
    if(n < 0) {
        return 0;
    }
    
    if(n == 0) {
        return 1;
    }
    
    return climbing_ladders(n-1) + climbing_ladders(n-2) + climbing_ladders(n-3);
}

int main() {
    int n;
    cin>>n;
    cout<<climbing_ladders(n)<<endl;
}