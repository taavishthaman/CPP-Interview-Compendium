#include<bits/stdc++.h>
using namespace std;

bool compare(int n1, int n2) {
    string s1 = to_string(n1);
    string s2 = to_string(n2);
    
    return s1 + s2 > s2 + s1;
}

int main() {
    vector<int> v = {10,11,20,30,3};
    sort(v.begin(), v.end(), compare);
    string op = "";
    for(int num : v) {
        op += to_string(num);
    }
    
    cout<<op<<endl;
}