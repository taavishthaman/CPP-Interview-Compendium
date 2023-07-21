#include<bits/stdc++.h>
using namespace std;

string palindromeBreak(string s) {
    int n = s.size();
    if(n <= 1) {
        return "";
    }
    
    for(int i=0; i<n/2; i++) {
        if(s[i] != 'a') {
            s[i] = 'a';
            return s;
        }
    }
    
    s[n-1] = 'b';
    return s;
}

int main() {
    cout<<palindromeBreak("aba")<<endl;
    cout<<palindromeBreak("abcba")<<endl;
}