#include<bits/stdc++.h>
using namespace std;

vector<char> firstnonrepeating(vector<char> str){
    vector<char> op;
    queue<char> q;
    unordered_map<char, int> m;
    
    int n = str.size();
    
    for(int i=0; i<n; i++) {
        char ch = str[i];
        cout<<ch<<endl;
        
        m[ch]++;
        q.push(ch);
        
        while(!q.empty() && m[q.front()] > 1) {
            q.pop();
        }
        
        if(q.empty()) {
            op.push_back('0');
        } else {
            op.push_back(q.front());
        }
    }
    
    return op;
}

int main() {
    //a a b c
    //a 0 b b
    //[a]
    //{ a : 1, }
    vector<char> ip = {'a', 'a', 'b', 'c'};
    vector<char> res = firstnonrepeating(ip);
    for(char num : res) {
        cout<<num<<", ";
    }
}