#include<iostream>
#include<vector>
using namespace std;

void number_spell(int num, vector<string> & spell) {
    if(num == 0) {
        return;
    }
    
    int last_digit = num % 10;
    number_spell(num/10, spell);
    cout<<spell[last_digit]<<" ";
}

int main() {
    vector<string> spell = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    number_spell(2567, spell);
}