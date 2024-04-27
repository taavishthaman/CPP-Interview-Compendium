#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterToLeft(vector<int> & stocks) {
    int n = stocks.size();
    stack<int> s;
    vector<int> op;
    
    op.push_back(-1);
    s.push(0);
    
    for(int i=1; i<n; i++) {
        int curr = stocks[i];
        while(!s.empty() && curr >= stocks[s.top()]) {
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

vector<int> stockSpanner(vector<int> & stocks) {
    vector<int> ngl = nextGreaterToLeft(stocks);
    
    vector<int> stock_span;
    
    for(int i=0; i<ngl.size(); i++) {
        int span = i - ngl[i];
        stock_span.push_back(span);
    }
    
    return stock_span;
}

int main() {
    //The span of the stock's price today is defined as the maximum number of consecutive days 
    //(starting from today and going backwards) for which the price of the stock was less than or equal to 
    //today's price.

    vector<int> stocks = {100, 80, 60, 70, 60, 75, 85};
    vector<int> v = stockSpanner(stocks);
    
    for(int num : v) {
        cout<<num<<", ";
    }
}