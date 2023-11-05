#include<bits/stdc++.h>
using namespace std;

int rotated_search(vector<int> & v, int key) {
    int s = 0;
    int e = v.size()-1;
    
    while(s <= e) {
        int m = (s+e) / 2;
        
        if(v[m] == key) {
            return m;
        }
        
        if(v[s] < v[m]) {
            if(key <= v[m] && key >= v[s]) {
                e = m-1;
            } else {
                s = m+1;
            }
        } else {
            if(key >= v[m] && key <= v[e]) {
                s = m+1;
            } else {
                e = m-1;
            }
        }
    }
    
    return -1;
}

int main() {
    vector<int> v = {4,5,6,7,0,1,2,3};
    int n = v.size();
    int result = rotated_search(v, 2);
    cout<<result<<endl;
}