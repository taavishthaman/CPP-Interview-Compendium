#include<bits/stdc++.h>
using namespace std;

void keypad_combinations(vector<string> & keypad, int i, string s, string a) {
    
    if(i == s.size()) {
        cout<<a<<endl;
        return;
    }
    
    int index = s[i] - '0';

    //Skip 0 and 1 index
    if(index == 0 || index == 1) {
        keypad_combinations(keypad, i+1, s, a);
    }
    for(char ch : keypad[index]) {
        keypad_combinations(keypad, i+1, s, a+ch);
    }
}

int main() {
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string s = "123";
    
    keypad_combinations(v, 0, s, "");
}