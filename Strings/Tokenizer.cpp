#include<bits/stdc++.h>
using namespace std;

vector<string> getTokens(string s) {
    stringstream ss(s);
    vector<string> tokens;
    string token;
    
    while(getline(ss, token, ' ')) {
        tokens.push_back(token);
    }
    
    return tokens;
}

int main() {
    string s = "This is a string with spaces.";
    vector<string> tokens = getTokens(s);
    
    for(string str : tokens) {
        cout<<str<<endl;
    }
}