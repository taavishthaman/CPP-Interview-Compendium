#include<bits/stdc++.h>
using namespace std;

int main() {
    string paragraph = "We are learning about STL string class. STL classes are quite powerful!";
    string word;
    cin>>word;
    
    int index = paragraph.find(word);
    
    while(index != -1) {
        cout<<index<<endl;
        index = paragraph.find(word, index+1);
    }
}