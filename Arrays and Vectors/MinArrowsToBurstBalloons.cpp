#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> v1, vector<int> v2) {
    return v1[1] < v2[1];
}

int countArrows(vector<vector<int>> & arr) {
    sort(arr.begin(), arr.end(), compare);
    int n = arr.size();
    int arrows = 1;
    int prevEnd = arr[0][1];
    for(int i=1; i<n; i++) {
        int currStart  = arr[i][0];
        int currEnd = arr[i][1];
        
        if(currStart < prevEnd) {
            
        }
        else {
            prevEnd = currEnd;
            arrows++;
        }
    }
    
    return arrows;
}

int main() {
    vector<vector<int>> v = {{7,9},{0,10},{4,5},{8,9},{4,10},{5,7}};
    cout<<countArrows(v)<<endl;
}