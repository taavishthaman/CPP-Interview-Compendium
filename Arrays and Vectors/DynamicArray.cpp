#include<bits/stdc++.h>
using namespace std;

class DynamicArray {
public:
    int * arr;
    int cs;
    int ms;
    
    DynamicArray(int default_size = 5) {
        arr = new int[default_size];
        cs = 0;
        ms = default_size;
    }
    
    void push_back(int num) {
        if(cs == ms) {
            int * oldArr = arr;
            arr = new int[2 * ms];
            
            for(int i=0; i<ms; i++) {
                arr[i] = oldArr[i];
            }
            ms = 2 * ms;
            delete [] oldArr;
        }
        arr[cs] = num;
        cs++;
    }
    
    bool isEmpty() {
        return cs == 0;
    }
    
    void pop_back() {
        if(!isEmpty()) {
            cs--;
        }
    }
    
    int capacity() {
        return ms;
    }
    
    int size() {
        return cs;
    }
    
    int operator[](int index) {
        return arr[index];
    }
};

int main() {
    DynamicArray v(13);
    
    for(int i=1; i<=13; i++) {
        v.push_back(i);
    }
    
    for(int i=0; i<13; i++) {
        cout<<v[i]<<", ";
    }
    cout<<endl;
    
    v.push_back(14);
    cout<<v[13]<<endl;
    
    v.pop_back();
    v.pop_back();
    cout<<"Current Size : "<<v.size()<<endl;
    cout<<"Current Capacity : "<<v.capacity()<<endl;
}