#include<bits/stdc++.h>
using namespace std;

void generate_brackets(string s, int n, int o, int c) {
    if(o + c == 2 * n) {
        cout<<s<<endl;
        return;
    }
    
    //Tree Pruning - controlling branches
    if(o < n) {
        generate_brackets(s+'(', n, o+1, c);
    }
    if(c < o) {
        generate_brackets(s+')', n, o, c+1);
    }
}

int main() {
    int n;
    cin>>n;
    generate_brackets("", n, 0, 0);
}