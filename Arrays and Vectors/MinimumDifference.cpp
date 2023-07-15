#include<bits/stdc++.h>
using namespace std;

pair<int, int> minDifference(vector<int> & a, vector<int> & b) {
    int i = 0;
    int j = 0;
    int n = a.size();
    int m = b.size();
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int min_so_far = INT_MAX;
    pair<int, int> res;
    
    while(i < n && j < m) {
        int diff = abs(a[i]-b[j]);
        if(diff < min_so_far) {
            min_so_far = diff;
            res.first = a[i];
            res.second = b[j];
        }
        
        if(a[i] < b[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    
    while(i < n) {
        int diff = abs(a[i]-b[j]);
        if(diff < min_so_far) {
            min_so_far = diff;
            res.first = a[i];
            res.second = b[j];
        }
        
        i++;
    } 
    
    while(j < m) {
        int diff = abs(a[i]-b[j]);
        if(diff < min_so_far) {
            min_so_far = diff;
            res.first = a[i];
            res.second = b[j];
        }
        
        j++;
    }
    
    return res;
}

int main() {
    vector<int> a = {23, 5, 10, 17, 30};
    vector<int> b = {26, 134, 135, 14, 19};
    pair<int, int> res = minDifference(a, b);
    cout<<res.first<<" "<<res.second<<endl;
}