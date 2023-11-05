#include <bits/stdc++.h>
using namespace std;

int findWays(string & str, int i, int j, unordered_set<string> & s) {
    if(i == str.size() && j == str.size()) {
        return 1;
    }
    
    if(j == str.size()) {
        return 0;
    }
    
    string cs = str.substr(i, j-i+1);
    if(s.find(cs) != s.end()) {
        return findWays(str, j+1, j+1, s) + findWays(str, i, j+1, s);
    }
    return findWays(str, i, j+1, s);
}

int wordBreak(string str, vector<string> &dictionary){
	unordered_set<string> s;
	for(string st : dictionary) {
	    s.insert(st);
	}
	
	int res = findWays(str, 0, 0, s);
	return res;
}