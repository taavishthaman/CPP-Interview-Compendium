#include <bits/stdc++.h>
using namespace std;

int reverse(int n){
	stack<int> s;
	int multiplier = 1;
	while(n > 0) {
	    int r = n % 10;
	    n = n / 10;
	    s.push(r);
	}
	
	int res = 0;
	while(!s.empty()) {
	    res += s.top() * multiplier;
	    s.pop();
	    multiplier *= 10;
	}
	
	return res;
}