#include<bits/stdc++.h>
using namespace std;

bool canPlaceBirds(vector<int> & nests, int B, int mid) {
    int position = nests[0];
    int birds = 1;
    
    for(int i=1; i<nests.size(); i++) {
        int current = nests[i];
        if(current - position >= mid) {
            position = current;
            birds++;
            
            if(birds == B) {
                return true;
            }
        }
    }
    
    return false;
}

int angryBirds(vector<int> & nests, int B) {
    sort(nests.begin(), nests.end());
    
    int n = nests.size();
    int lo = 0;
    int hi = nests[n-1] - nests[0];
    int res = -1;
    
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        bool canPlace = canPlaceBirds(nests, B, mid);
        if(canPlace) {
            res = mid;
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    
    return res;
}

int main() {
    int B = 3;
    vector<int> nests = {1,2,4,8,9};
    
    int res = angryBirds(nests, B);
    cout<<res<<endl;
}