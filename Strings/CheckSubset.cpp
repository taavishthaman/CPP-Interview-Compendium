#include<bits/stdc++.h>
using namespace std;

bool checkSubset(string s1, string s2) {
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    
    while(i >= 0 && j >= 0) {
        if(s1[i] == s2[j]) {
            j--;
        }
        i--;
    }
    return j == -1;    
}

int main() {
    string s2 = "cines";
    string s1 = "codingminutes";
    
    cout<<checkSubset(s1, s2)<<endl;
}