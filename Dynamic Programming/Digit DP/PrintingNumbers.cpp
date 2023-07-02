#include<bits/stdc++.h>
using namespace std;

void printNumbers(string & s, int i, bool last, string op) {
    if(i == s.size()) {
        cout<<op<<" ";
        return;
    }
    
    int num = s[i]-'0';
    if(last) {
        for(int k=0; k<=num; k++) {
            if(k == num) {
                printNumbers(s, i+1, true, op+to_string(k));
            }
            else {
                printNumbers(s, i+1, false, op+to_string(k));
            }
        }
    } else {
        for(int k=0; k<=9; k++) {
            printNumbers(s,i+1, false, op+to_string(k));
        }
    }
}

int main() {
    string s = "1234";
    int n = s.size();
    printNumbers(s, 0, true, "");
}