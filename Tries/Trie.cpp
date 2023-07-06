#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    char ch;
    unordered_map<char, Node*> m;
    bool isTerminal;
    
    Node(char ch) {
        this->ch = ch;
        this->isTerminal = false;
    }
};

class Trie {
public:
    Node * root;
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node * temp = root;
        
        for(char ch : word) {
            if(temp->m.find(ch) == temp->m.end()) {
                temp->m[ch] = new Node(ch);
            }
            temp = temp->m[ch];
        }
        
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        Node * temp = root;
        
        for(char ch : word) {
            if(temp->m.find(ch) == temp->m.end()) {
                return false;
            }
            temp = temp->m[ch];
        }
        
        return temp->isTerminal;
    }
};

int main() {
    vector<string> words = {"cats", "cat", "hello", "hell", "none"};
    vector<string> searchWords = {"cat", "hello", "no", "none", "six"};
    
    Trie t;
    for(string w : words) {
        t.insert(w);
    }
    
    for(string w : searchWords) {
        if(t.search(w)) {
            cout<<w<<" exists inside the word list."<<endl;
        } else {
            cout<<w<<" does not exist inside the word list."<<endl;
        }
    }
}