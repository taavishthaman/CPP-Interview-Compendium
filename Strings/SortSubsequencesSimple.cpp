#include<bits/stdc++.h>
using namespace std;

void findSubsets(string s, string o, vector<string> & op) {
    if(s.size() == 0) {
        op.push_back(o);
        return;
    }

    char ch = s[0];
    string ros = s.substr(1);
    findSubsets(ros, o, op);
    findSubsets(ros, o+ch, op);
}

bool compare(string s1, string s2) {
    if(s1.size() == s2.size()) {
        return s1 < s2;
    }

    return s1.size() < s2.size();
}

int main() {
    string s = "abc";
    vector<string> op;
    findSubsets(s, "", op);

    sort(op.begin(), op.end(), compare);

    for(string str : op) {
        cout<<str<<", ";
    }
}