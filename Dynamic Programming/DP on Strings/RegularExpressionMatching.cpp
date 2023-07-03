#include<bits/stdc++.h>
using namespace std;

bool regexMatch(string s, string p, int i, int j) {
    if(i == s.size() && j == p.size()) {
        return true;
    }
    if(j == p.size()) {
        return false;
    }
    
    int ans = 0;
    if(j+1 < p.size() && p[j+1] == '*') {
        //Match current character
        if(i < s.size() && (s[i] == p[j] || p[j] == '.')) {
            ans |= regexMatch(s, p, i+1, j);
        }
        //Don't match 
        ans |= regexMatch(s, p, i, j+2);
    }
    else {
        if(i < s.size() && (s[i] == p[j] || p[j] == '.')) {
            ans |= regexMatch(s, p, i+1, j+1);
        }
    }
    
    return ans;
}

int main() {
    string s = "ab";
    string p = "ab*";
    cout<<regexMatch(s, p, 0, 0)<<endl;
}