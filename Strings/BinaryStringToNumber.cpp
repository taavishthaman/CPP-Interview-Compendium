#include<bits/stdc++.h>
using namespace std;

int binaryStringToNumber(string s) {
    int n = s.size();
    
    int res = 0;
    int p = 0;
    
    for(int i=n-1; i>=0; i--) {
        int num = s[i]-'0';
        res += pow(2, p) * num;
        p++;
    }
    
    return res;
}

int main() {
    string s = "111";
    cout<<binaryStringToNumber(s)<<endl;
    cout<<binaryStringToNumber("10010100100010101011")<<endl;
}