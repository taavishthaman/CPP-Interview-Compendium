#include<bits/stdc++.h>
using namespace std;

bool canDivideAmongK(vector<int> & coins, int k, int mid) {
    int current_sum = 0;
    int partitions = 0;
    
    for(int i=0; i<coins.size(); i++) {
        if(current_sum + coins[i] >= mid) {
            partitions += 1;
            current_sum = 0;
        } else {
            current_sum += coins[i];
        }
    }
    
    return partitions >= k;
}

int game_of_greed(vector<int> & coins, int k) {
    int s = 0;
    int e = 0;
    int ans = 0;
    for(int num : coins) {
        e += num;
    }
    
    while(s <= e) {
        int mid = (s + e) / 2;
        bool isPossible = canDivideAmongK(coins, k, mid);
        if(isPossible) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    
    return ans;
}

int main() {
    vector<int> v = {1,2,3,4};
    cout<<game_of_greed(v, 3)<<endl;
}