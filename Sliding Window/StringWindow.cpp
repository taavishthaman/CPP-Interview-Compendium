#include<bits/stdc++.h>
using namespace std;

string max_window_size(string s, string t) {
    if(s.size() < t.size()) {
        return "";
    }
    
    vector<int> FP(256, 0);
    vector<int> FS(256, 0);
    
    for(int i=0; i<t.size(); i++) {
        FP[t[i]]++;
    }
    
    int cnt = 0;
    int start = 0;
    int min_len = INT_MAX;
    int window_start = -1;
    
    for(int i=0; i<s.size(); i++) {
        char ch = s[i];
        FS[ch]++;
        
        if(FP[ch] != 0 && FS[ch] <= FP[ch]) {
            cnt++;
        }
        
        if(cnt == t.size()) {
            while(FP[s[start]] == 0 || FS[s[start]] > FP[s[start]]) {
                FS[s[start]]--;
                start++;
            }
            
            int curr_window_len = i-start+1;
            
            if(curr_window_len < min_len) {
                min_len = curr_window_len;
                window_start = start;
            }
        }
    }
    
    if(window_start == -1) {
        return "";
    }
    
    return s.substr(window_start, min_len);
}

int main() {
    string s = "A";
    string p = "AA";
    cout<<max_window_size(s, p)<<endl;
}