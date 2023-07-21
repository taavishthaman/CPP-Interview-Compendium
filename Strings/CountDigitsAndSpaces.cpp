#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "This is a sentence with more than 1 and less than 10 digits and more than 1 and less than 30 spaces";
    int count_spaces = 0;
    int count_digits = 0;
    
    for(char ch : s) {
        if(ch == ' ') {
            count_spaces++;
        }
        else if(ch >= '0' && ch <= '9') {
            count_digits++;
        }
    }
    
    cout<<count_spaces<<" "<<count_digits<<endl;
}