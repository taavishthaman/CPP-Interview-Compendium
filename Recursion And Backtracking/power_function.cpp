#include<iostream>
using namespace std;

int power(int a, int n) {
    if(n == 0) {
        return 1;   
    }
    
    return a * power(a, n-1);
}

int fast_power(int a, int n) {
    if(n == 0) {
        return 1;
    }
    
    int half_power = fast_power(a, n/2);
    int half_power_sq = half_power * half_power;
    
    if(n % 2) {
        return a * half_power_sq;
    }
    
    return half_power_sq;
}

int main() {
    int a, n;
    cin>>a>>n;
    cout<<power(a, n)<<endl;
    cout<<fast_power(a, n)<<endl;
}

