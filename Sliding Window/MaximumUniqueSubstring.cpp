#include<bits/stdc++.h>
using namespace std;

string unique_substring(string str) {
    unordered_map<char, int> m;
    int n = str.size();
    int i=0;
    int j=0;
    int len = 0;
    int max_len = 0;
    int start = -1;
    
    while(j < n) {
        char ch = str[j];
        
        if(m.count(ch) != 0 && m[ch] >= i) {
            i = m[ch] + 1;
            len = j-i;
        }
        
        m[ch] = j;
        j++;
        len++;
        
        if(len > max_len) {
            max_len = len;
            start = i;
        }
    }
    
    return str.substr(start, max_len);
}

int main() {
    string str = "abcabed";
    cout<<unique_substring(str)<<endl;
}