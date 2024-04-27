#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerToLeft(vector<int> & hist) {
    int n = hist.size();
    vector<int> op;
    stack<int> s;
    s.push(0);
    op.push_back(-1);
    for(int i=1; i<n; i++) {
        int curr = hist[i];
        while(!s.empty() && hist[s.top()] > curr) {
            s.pop();
        }
        if(s.empty()) {
            op.push_back(-1);
        } else {
            op.push_back(s.top());
        }
        
        s.push(i);
    }
    
    return op;
}

vector<int> nextSmallerToRight(vector<int> & hist) {
    int n = hist.size();
    vector<int> op;
    stack<int> s;
    s.push(n-1);
    op.push_back(n);
    for(int i=n-2; i>=0; i--) {
        int curr = hist[i];
        while(!s.empty() && hist[s.top()] > curr) {
            s.pop();
        }
        if(s.empty()) {
            op.insert(op.begin(), n);
        } else {
            op.insert(op.begin(), s.top());
        }
        
        s.push(i);
    }
    
    return op;
}
 
int getMaxArea(vector<int> hist){
    vector<int> nsl = nextSmallerToLeft(hist);
    vector<int> nsr = nextSmallerToRight(hist);
    
    int n = hist.size();
    int max_area = 0;
    for(int i=0; i<n; i++) {
        int area = (nsr[i] - nsl[i] - 1) * hist[i];
        
        max_area = max(max_area, area);
    }
    
    return max_area;
}

int main() {
    vector<int> v = {6, 2, 5, 4, 5, 1, 6};
    int res = getMaxArea(v);
    cout<<res<<endl;
}