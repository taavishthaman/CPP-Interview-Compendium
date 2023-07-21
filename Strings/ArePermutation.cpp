#include<bits/stdc++.h>
using namespace std;

bool checkPermutations(string s, string t) {
    if(s.size() != t.size()) {
        return false;
    }
    
    int n = s.size();
    vector<int> v(256, 0);
    
    for(int i=0; i<n; i++) {
        v[s[i]]++;
    }
    
    for(int i=0; i<n; i++) {
        v[t[i]]--;
    }
    
    for(int i=0; i<256; i++) {
        if(v[i] != 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    string s = "test";
    string t = "ttew";
    
    cout<<checkPermutations(s, t)<<endl;
    cout<<checkPermutations("anagram", "naamarg")<<endl;
}