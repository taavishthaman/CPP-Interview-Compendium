#include<iostream>
using namespace std;

void print_increasing(int n) {
    if(n == 0) {
        return;
    }
    
    print_increasing(n-1);
    cout<<n<<", ";
}

void print_decreasing(int n) {
    if(n == 0) {
        return;
    }
    
    cout<<n<<", ";
    print_decreasing(n-1);
}


int main() {
    int n;
    cin>>n;
    print_increasing(n);
    cout<<endl;
    print_decreasing(n);
}