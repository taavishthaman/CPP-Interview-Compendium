#include<bits/stdc++.h>
using namespace std;

vector<string> tokenizer(string & str) {
    stringstream ss(str);
    string token;
    vector<string> op;
    while(getline(ss, token, ' ')) {
        if(token != " ") {
            string tcopy = "";
            for(int i=0; i<token.size(); i++) {
                if(i == 0) {
                    tcopy += toupper(token[0]);
                } else {
                    tcopy += tolower(token[i]);
                }
            }
            op.push_back(tcopy);
        } else {
            op.push_back(token);
        }
    }
    
    return op;
}

string normalize(const string &sentence) {
    string copy = sentence;
    //Make the changes in copy, and return it
    vector<string> tokens = tokenizer(copy);
    string op = "";

    int n = tokens.size();
    
    for(int i=0; i<n; i++) {
        op += tokens[i];
        op += " ";
    }

    if(copy[copy.size()-1] != ' ') {
        op = op.substr(0, op.size()-1);
    }
    return op;
}