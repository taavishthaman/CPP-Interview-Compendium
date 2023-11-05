#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> box1, vector<int> box2) {
    return box1[2] < box2[2];
}

bool canPlace(vector<int> box1, vector<int> box2) {
    if(box1[0] < box2[0] && box1[1] < box2[1] && box1[2] < box2[2]) {
        return true;
    }
    return false;
}

int boxStacking(vector<vector<int>> & boxes, int n) {
    sort(boxes.begin(), boxes.end(), compare);
    
    vector<int> dp(n, 0);
    for(int i=0; i<n; i++) {
        dp[i] = boxes[i][2];
    }
    
    int largest = 0;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(canPlace(boxes[j], boxes[i])) {
                dp[i] = max(dp[i], boxes[i][2] + dp[j]);
                largest = max(largest, dp[i]);
            }
        }
    }
    
    return largest;
}

int main() {
    vector<vector<int>> boxes = {
        {2,1,2},
        {3,2,3},
        {2,2,8},
        {2,3,4},
        {2,2,1},
        {4,4,5}
    };
    
    cout<<boxStacking(boxes, boxes.size())<<endl;
}