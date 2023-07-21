#include<bits/stdc++.h>
using namespace std;

int main() {
    string paragraph = "We are learning about STL string class. STL classes are quite powerful!";
    string word;
    cin>>word;
    int index = paragraph.find(word);
    if(index == -1) {
        cout<<"String not found!"<<endl;
    } else {
        cout<<"First Index "<<index<<endl;
        cout<<"Second Index "<<paragraph.find(word, index+1);
    }
}