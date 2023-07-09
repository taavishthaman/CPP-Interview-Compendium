#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    string key;
    int value;
    
    Node(string key, int value) {
        this->key = key;
        this->value = value;
    }
};

class LRUCache {
public:
    int maxSize;
    list<Node> l;
    unordered_map<string, list<Node>::iterator> m;
    
    LRUCache(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void insertKeyValue(string key, int value) {
        //2 cases
        if(m.count(key) != 0) {
            //replace the old value and update
            auto it = m[key];
            it->value = value;
        }
        else {
            //Check if cache is full
            //If full remove the least recently used item
            if(l.size() == maxSize) {
                Node last = l.back();
                m.erase(last.key); //remove from hash map
                l.pop_back(); //remove from linked list
            }
            
            Node n(key, value);
            l.push_front(n);
            m[key] = l.begin();
        }
    }
    
    int * getValue(string key) {
        if(m.count(key) != 0) {
            auto it = m[key];
            int value = it->value;
            l.push_front(*it);
            l.erase(it);
            m[key] = l.begin();
            return &l.begin()->value;
        }
        
        return NULL;
    }
    
    string getMostRecentKey() {
        return l.front().key;
    }
};

int main() {
    LRUCache lru(3);
    lru.insertKeyValue("mango", 10);
    lru.insertKeyValue("apple", 20);
    lru.insertKeyValue("guava", 30);
    cout<<lru.getMostRecentKey()<<endl;
    
    lru.insertKeyValue("banana", 20);
    
    if(lru.getValue("apple") == NULL) {
        cout<<"apple does not exist."<<endl;
    }
    
    if(lru.getValue("guava") == NULL) {
        cout<<"guava does not exist."<<endl;
    }
    
    if(lru.getValue("mango") == NULL) {
        cout<<"mango does not exist."<<endl;
    }
    
    if(lru.getValue("banana") == NULL) {
        cout<<"apple does not exist."<<endl;
    }
}

/*
    LRU cache is a combination of doubly linked list and a hash table
    
    [k,v]      [Key, Address of Node]
     ||        [Key, Address of Node]
    [k,v]      [Key, Address of Node]
     ||        [Key, Address of Node]
    [k,v]          (Hash Table)
     ||
    [k,v]
    
    DLL
*/