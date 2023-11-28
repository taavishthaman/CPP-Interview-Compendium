#include<bits/stdc++.h>
using namespace std;

int find_ways(string str, int i, int j, unordered_set<string> & u_set) {
    if(j == str.size() && i == j) {
        return 1;
    }
    
    if(j == str.size() && i != j) {
        return 0;
    }
    
    string sub = str.substr(i, (j-i+1));
    
    int ways = 0;
    if(u_set.find(sub) != u_set.end()) {
        ways += find_ways(str, j+1, j+1, u_set) + find_ways(str, i, j+1, u_set);
    } else {
        ways += find_ways(str, i, j+1, u_set);
    }
    
    return ways;
}

int wordBreak(string str, vector<string> &dictionary){
	unordered_set<string> u_set;
	for(string s : dictionary) {
	    u_set.insert(s);
	}
	
	return find_ways(str, 0, 0, u_set);
}

int main() {
    vector<string> dictionary = {"i", "like", "sam", "sung", "samsung", "mobile"};
    string str = "ilikesamsungmobile";
    cout<<wordBreak(str, dictionary)<<endl;
}