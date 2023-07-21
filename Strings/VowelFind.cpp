#include<bits/stdc++.h>
using namespace std;

string vowelFind(string & s) {
    int n = s.size();
    unordered_map<char, int> m;
    m['a'] = 1; m['e'] = 1; m['i'] = 1; m['o'] = 1; m['u'] = 1;
    
    string op = "";
    for(int i=0; i<n; i++) {
        char ch = s[i];
        if(m.count(ch) == 1) {
            op += ch;
        }
    }
    
    return op;
}

int main() {
    string s = "aeoibsddaeioudb";
    cout<<vowelFind(s)<<endl;
}