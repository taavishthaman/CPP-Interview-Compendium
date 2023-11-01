#include<bits/stdc++.h>
using namespace std;

string smallestWindow(string str){
    //Complete this method
    if(str.size() <= 1) {
        return str;
    }
    unordered_map<char, int> m;
    int i=0, j=0;
    int len = 0;
    int max_len = 0;
    int start = -1;
    while(j < str.size()) {
        char ch = str[j];
        
        if(m.count(ch) != 0 && m[ch] >= i) {
            i = m[ch]+1;
            len = j-i;
        }
        
        len++;
        m[ch] = j;
        j++;
        if(len > max_len) {
            max_len = len;
            start = i;
        }
    }
    
    return str.substr(start, max_len);
    
}