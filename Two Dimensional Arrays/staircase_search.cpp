#include <iostream>
#include <vector>
using namespace std;

vector<int> staircase_search(vector<vector<int>> & arr, int target) {
    int n = arr.size();
    int m = arr[0].size();
    
    if(target < arr[0][0] || target > arr[n-1][m-1]) {
        return {-1,-1};
    }
    
    //Initialize the pointer at the first row and last column
    int i = 0;
    int j = m - 1;
    
    while(i < n && j >= 0) {
        if(arr[i][j] == target) {
            return {i, j};
        }
        else if(target < arr[i][j]) {
            j--;
        } else {
            i++;
        }
    }
    
    return {-1,-1};
}

int main()
{
    vector<vector<int>> arr = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    
    vector<int> res = staircase_search(arr, 11);
    cout<<res[0]<<" "<<res[1]<<endl;

    return 0;
}
