#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int i, int j, int count) {
    if(i == s1.size() || j == s2.size()) {
        return count;
    }
    
    if(s1[i] == s2[j]) {
        return lcs(s1, s2, i+1, j+1, count + 1);
    }
    
    else {
        return max({count, lcs(s1, s2, i+1, j, 0), lcs(s1, s2, i, j+1, 0)});
    }
}

int main() {
    string s1 = "abcde";
    string s2 = "bce";
    
    cout<<lcs(s1, s2, 0, 0, 0)<<endl;
}