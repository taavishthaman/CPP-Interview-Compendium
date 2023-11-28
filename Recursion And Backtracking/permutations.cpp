#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

void permutations(string s, int i, vector<string> & op) {
    if(i == s.size() - 1) {
        //Only one character left so return
        op.push_back(s);
        return;
    }
    
    for(int j=i; j<s.size(); j++) {
        //Swap the character at the current index with character on every other index
        swap(s[i], s[j]);
        //Find the permutations for the rest of the string
        permutations(s, i+1, op);
        //Swap again to reset the string
        swap(s[i], s[j]);
    }
}

int main() {
    string s = "abc";
    vector<string> op;
    permutations(s, 0, op);
    for(string str : op) {
        cout<<str<<", ";
    }
}