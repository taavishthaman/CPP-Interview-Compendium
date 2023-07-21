#include<bits/stdc++.h>
using namespace std;

string space20(string s) {
    //Naive Solution
    string op = "";
    int n = s.size();
    
    for(int i=0; i<n; i++) {
        char ch = s[i];
        if(ch == ' ') {
            op += "%20";
        }
        else {
            op += ch;
        }
    }
    
    return op;
}

void space20(char * s) {
    int count_spaces = 0;
    int len = 0;
    while(s[len] != '\0') {
        if(s[len] == ' ') {
            count_spaces ++;
        }
        len++;
    }
    
    int new_len = len + 2 * count_spaces;
    int i = len;
    int j = new_len;
    
    for(i=len; i>=0; i--) {
        char ch = s[i];
        if(ch != ' ') {
            s[j] = ch;
            j--;
        }
        else {
            s[j] = '0';
            s[j-1] = '2';
            s[j-2] = '%';
            j-=3;
        }
    }
}

int main() {
    string s = "hello world! How are you?";
    string op = space20(s);
    cout<<op<<endl;
    char arr[100] = "hello world! How are you?";
    space20(arr);
    
    for(int i=0; arr[i] != '\0'; i++) {
        cout<<arr[i];
    }
}