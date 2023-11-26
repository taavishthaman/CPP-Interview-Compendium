#include <iostream>
#include <vector>
using namespace std;

void wave_print(vector<vector<int>> & arr) {
    int n = arr.size();
    int m = arr[0].size();
    
    bool dir = 0;
    int col = m-1;
    
    while(col >= 0) {
        if(dir == 0) {
            for(int row = 0; row <= n-1; row++) {
                cout<<arr[row][col]<<" ";
            }
        } else {
            for(int row=n-1; row >= 0; row--) {
                cout<<arr[row][col]<<" ";
            }
        }
        col--;
        dir = !dir;
    }
}

int main()
{
    vector<vector<int>> arr = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    
    wave_print(arr);

    return 0;
}
