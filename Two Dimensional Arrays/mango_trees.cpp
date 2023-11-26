#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_possible_trees(vector<vector<char>> & arr) {
    //2D prefix sums
    int n = arr.size();
    int m = arr[0].size();
    
    vector<vector<int>> prefix(n, vector<int>(m, 0));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i == 0 && j == 0) {
                prefix[i][j] = arr[i][j] == '#' ? 1 : 0;
            }
            else if(i == 0) {
                prefix[i][j] = prefix[i][j-1] + (arr[i][j] == '#' ? 1 : 0);
            }
            else if(j == 0) {
                prefix[i][j] = prefix[i-1][j] + (arr[i][j] == '#' ? 1 : 0);
            } else {
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + (arr[i][j] == '#' ? 1 : 0);
            }
        }
    }
    
    int max_trees = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int s1 = prefix[i][j];
            int s2 = prefix[i][m-1] - s1;
            int s3 = prefix[n-1][j] - s1;
            int s4 = prefix[n-1][m-1] - s1 - s2 - s3;
            max_trees = max(max_trees, min({s1,s2,s3,s4}));
        }
    }
    
    return max_trees;
}

int main()
{
    vector<vector<char>> arr = {
        {'.','#','#','.','.','.'},
        {'#','.','.','#','#','.'},
        {'.','#','.','.','.','.'},
        {'.','#','#','.','.','#'},
        {'#','.','.','#','#','.'},
        {'.','#','.','.','.','.'}
    };
    
    cout<<max_possible_trees(arr)<<endl;

    return 0;
}
