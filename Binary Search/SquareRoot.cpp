#include<bits/stdc++.h>
using namespace std;

float squareRoot(int N, int P) {
    float res = 0;
    
    int lo = 0;
    int hi = N;
    
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(mid * mid == N) {
            return mid;
        }
        
        else if(mid * mid < N) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    float factor = 0.1;
    for(int i=0; i<P; i++) {
        
        for(int j=1; j<=9; j++) {
            while(res * res < N) {
                res += factor;
            }
        }
        
        if(res * res == N) {
            return res;
        }
        
        res -= factor;
        factor /= 10;
    }
    
    return res;
}

int main() {
    int N = 13;
    int P = 5;
    float res = squareRoot(N, P);
    cout<<res<<endl;
}