#include<bits/stdc++.h>
using namespace std;

int col = 0;
vector<string> splitString(string str) {
    stringstream ss(str);
    string token;
    vector<string> tokens;
    while(getline(ss, token, ' ')) {
        tokens.push_back(token);
    }
    
    return tokens;
}

vector<vector<string>> tokenise(vector<string> & v) {
    int n = v.size();
    vector<vector<string>> op;
    for(int i=0; i<n; i++) {
        string cs = v[i];
        vector<string> tokens = splitString(cs);
        op.push_back(tokens);
    }
    
    return op;
}

bool compare(vector<string> & v1, vector<string> & v2) {
    return stoi(v1[col-1]) < stoi(v2[col-1]);
}

void stringKeySort(vector<string> & v, int c, bool reverse, string type) {
    vector<vector<string>> tokens = tokenise(v);
    col = c;
    sort(tokens.begin(), tokens.end(), compare);
    
    for(vector<string> v : tokens) {
        for(string s : v) {
            cout<<s<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    vector<string> v = {"92 022", "82 12", "77 13"};
    
    int c = 2;
    bool reverse = false;
    string type = "numeric";
    
    stringKeySort(v, c, reverse, type);
}