#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string, vector<int>> p1, pair<string, vector<int>> p2) {
    int sum1 = p1.second[0] + p1.second[1] + p1.second[2];
    int sum2 = p2.second[0] + p2.second[1] + p2.second[2];
    
    return sum1 > sum2;
}

int main() {
    vector<pair<string, vector<int>>> student_marks = {
        {"Rohan", {10, 20, 11}},
        {"Prateek", {10,21,3}},
        {"Vivek", {4,5,6}},
        {"Rijul", {10,13,20}}
    };
    
    sort(student_marks.begin(), student_marks.end(), compare);
    
    int n = student_marks.size();
    
    for(int i=0; i<n; i++) {
        cout<<student_marks[i].first<<", ";
        for(int j=0; j<student_marks[i].second.size(); j++) {
            cout<<student_marks[i].second[j]<<" ";
        }
        cout<<endl;
    }
}