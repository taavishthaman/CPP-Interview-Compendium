#include<bits/stdc++.h>
using namespace std;

void min_pair(vector<int> & a1, vector<int> & a2) {
    sort(a2.begin(), a2.end());
    int n1 = a1.size();
    int n2 = a2.size();
    
    int diff = INT_MAX;
    int p1, p2;
    
    for(int i=0; i<n1; i++) {
        //This will return the index of element just larger than the target element
        int lb = lower_bound(a2.begin(), a2.end(), a1[i]) - a2.begin();
        int num = a1[i];
        
        if(lb >= 1 && num - a2[lb-1] < diff) {
            diff = num-a2[lb-1];
            p1 = a2[lb-1];
            p2 = num;
        }
        
        if(lb != n2 && a2[lb] - num < diff) {
            diff = a2[lb] - num;
            p1 = num;
            p2 = a2[lb];
        }
    }
    
    cout<<p1<<", "<<p2<<endl;
}

int main() {
    vector<int> a1 = {-1, 5, 10, 20, 3};
    vector<int> a2 = {26, 132, 135, 15, 17};
    min_pair(a1, a2);
}