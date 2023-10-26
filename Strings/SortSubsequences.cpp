#include<bits/stdc++.h>
using namespace std;

vector<string> printSubstrings(string s) {
    if(s.size() == 0) {
        vector<string> b;
        b.push_back("");
        return b;
    }
    
    char ch = s[0];
    string ros = s.substr(1, s.size());
    
    vector<string> subprob = printSubstrings(ros);
    vector<string> op;
    for(string s : subprob) {
        op.push_back(s);
        op.push_back(ch+s);
    }
    
    return op;
}

bool compare(string s1, string s2) {
    if(s1.size() == s2.size()) {
        return s1 < s2;
    }
    
    return s1.size() < s2.size();
}

int main() {
    string s = "abcd";
    vector<string> op = printSubstrings(s);
    sort(op.begin(), op.end(), compare);
    
    for(string str : op) {
        cout<<str<<" ";
    }
}