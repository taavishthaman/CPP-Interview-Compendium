#include<iostream>
#include<vector>
using namespace std;

int binary_strings(int n, string s) {
    if(n == 0) {
        cout<<s<<endl;
        return 1;
    }
    
    if(n == 1) {
        s += '0';
        cout<<s<<endl;
        s.pop_back();
        s += '1';
        cout<<s<<endl;
        return 2;
    }
    
    return binary_strings(n-1, s+'0') + binary_strings(n-2, s+"10");
}

int main() {
    int n;
    cin>>n;
    cout<<binary_strings(n, "")<<endl;
}

