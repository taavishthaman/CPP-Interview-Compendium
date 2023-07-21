#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int n = s.size();
    
    for(int i=0; i<n/2; i++) {
        if(s[i] != s[n-1-i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    string s1 = "abcdcba";
    string s2 = "abcbea";
    
    cout<<isPalindrome(s1)<<endl;
    cout<<isPalindrome(s2)<<endl;
}