#include<bits/stdc++.h>
using namespace std;

string shortestPath(string s) {
    //First calculate displacement
    int x = 0;
    int y = 0;
    
    for(char ch : s) {
        if(ch == 'S') {
            y--;
        }
        else if(ch == 'N') {
            y++;
        }
        else if(ch == 'E') {
            x++;
        }
        else {
            x--;
        }
    }
    
    string op = "";
    if(y > 0) {
        while(y != 0) {
            op += 'N';
            y--;
        }
    }
    else {
        while(y != 0) {
            op += 'S';
            y++;
        }
    }
    
    if(x > 0) {
        while(x != 0) {
            op += 'E';
            x--;
        }
    }
    else {
        while(x != 0) {
            op += 'W';
            x++;
        }
    }
    
    return op;
}

int main() {
    string s = "SNNNEWE";
    cout<<shortestPath(s)<<endl;
}