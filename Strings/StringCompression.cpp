#include<bits/stdc++.h>
using namespace std;

int compress(vector<char> & s) {
    int n = s.size();
    int count = 1;
    int i = 0;
    int k = 0;
    for(i=0; i<n-1; i++) {
        if(s[i] != s[i+1]) {
            if(count > 1) {
                s[k] = s[i];
                k++;
                string count_str = to_string(count);
                for(int j=0; j<count_str.size(); j++) {
                    s[k] = count_str[j];
                    k++;
                }
                count = 1;
            } else {
                s[k] = s[i];
            }
        }
        else {
            count++;
        }
    }
    
    if(count > 1) {
        s[k] = s[i];
        k++;
        string count_str = to_string(count);
        for(int j=0; j<count_str.size(); j++) {
            s[k] = count_str[j];
            k++;
        }
    }
    else {
        s[k] = s[i];
        k++;
    }
    
    return k;
}

int main() {
    vector<char> v = {'a','a','b','b','c','c','c','c','c','c','c','c','c','c','c','c','d','d'};
    int len = compress(v);
    for(int i=0; i<len; i++) {
        cout<<v[i];
    }
}