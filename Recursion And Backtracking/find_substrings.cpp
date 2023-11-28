#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2) {
    if(s1.size() == s2.size()) {
        return s1 < s2; //lexicographical comparison
    }
    
    return s1.size() < s2.size();
}

void find_subsets(string s, string a, vector<string> & op) {
    if(s.size() == 0) {
        op.push_back(a);
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    //Include current character in output
    find_subsets(ros, a+ch, op);
    //Exclude current character in output
    find_subsets(ros, a, op);
}

int main()
{
    string s = "abc";
    vector<string> op;
    find_subsets(s, "", op);
    sort(op.begin(), op.end(), compare);
    for(string s : op) {
        cout<<s<<", ";
    }
    return 0;
}
