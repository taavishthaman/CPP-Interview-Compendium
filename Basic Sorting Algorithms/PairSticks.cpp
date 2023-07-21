#include<bits/stdc++.h>
using namespace std;

int pairSticks(vector<int> & v, int D) {
    sort(v.begin(), v.end());
    int count = 0;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(v.size() >= 2 && abs(v[i]-v[j]) <= D) {
                count++;
                v.erase(v.begin()+i);
                v.erase(v.begin()+j);
                i=0;
                j=0;
            }
        }   
    }
    
    return count;
}

int main() {
    vector<int> v = {1, 3, 3, 9, 4};
    int D = 2;
    int res = pairSticks(v, D);
    cout<<res<<endl;
}