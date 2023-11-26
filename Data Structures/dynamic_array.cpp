#include<iostream>
using namespace std;

class Vector {
    int * arr;
    int cs;
    int ms;
public:
    
    Vector(int max_size=1) {
        cs = 0;
        ms = max_size;
        arr = new int[ms];
    }
    
    void push_back(int val) {
        if(cs == ms) {
            //Reallocation
            int * oldArr = arr;
            ms = 2 * ms;
            arr = new int[ms];
            
            //copy to new array
            for(int i=0; i<cs; i++) {
                arr[i] = oldArr[i];
            }
            
            //delete old array
            delete [] oldArr;
        }
        arr[cs] = val;
        cs++;
    }
    
    void pop_back() {
        //Check if vector is not empty
        if(cs > 0) cs--;
    }
    
    bool isEmpty() {
        return cs == 0;
    }
    
    int front() const{
        return arr[0];
    }
    
    int back() const{
        return arr[cs-1];
    }
    
    int at(int i) const{
        return arr[i];
    }
    
    int size() const{
        return cs;
    }
    
    int capacity() {
        return ms;
    }
    
    int operator[](const int i) {
        return arr[i];
    }
};

int main() {

    Vector v;
    for(int i=1; i<=6; i++) {
        v.push_back(i);
    }
    
    v.pop_back();
    
    cout<<"Size "<<v.size()<<endl;
    cout<<"Capacity "<<v.capacity()<<endl;
    cout<<"Front: "<<v.front()<<" ,Back: "<<v.back()<<endl;
    
    for(int i=0; i<v.size(); i++) {
        cout<<v[i]<<", ";
    }
}