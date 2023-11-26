#include <iostream>
#include <vector>
using namespace std;

void spiral_print(vector<vector<int>> & arr) {
    int n = arr.size();
    int m = arr[0].size();
    
    int sr = 0;
    int sc = 0;
    int er = n-1;
    int ec = m-1;
    
    while(sr <= er && sc <= ec) {
        //Print the first row
        for(int col = sc; col <= ec; col++) {
            cout<<arr[sr][col]<<" ";
        }
        
        //Print the last col
        for(int row = sr+1; row <= er; row++) {
            cout<<arr[row][ec]<<" ";
        }
        
        //Print the last row
        for(int col = ec-1; col >= sc; col--) {
            cout<<arr[er][col]<<" ";
        }
        
        //Print the first col
        for(int row = er-1; row >= sr+1; row--) {
            cout<<arr[row][sc]<<" ";
        }
        
        sr++;
        sc++;
        er--;
        ec--;
    }
}

int main()
{
    vector<vector<int>> arr = {
        {1,2,3,4},
        {12,13,14,5},
        {11,16,15,6},
        {10,9,8,7}
    };
    
    spiral_print(arr);

    return 0;
}
