#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
    sort(s.begin(), s.end());
    string op = "";
    int n = s.size();
    
    for(int i=0; i<n-1; i++) {
        if(s[i] != s[i+1]) {
            op += s[i];
        }
    }
    
    op += s[s.size()-1];
    return op;
}

int main() {
    string s = "geeksforgeeks";
    cout<<removeDuplicates(s)<<endl;
}