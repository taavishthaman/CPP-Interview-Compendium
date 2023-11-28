#include <iostream>
#include <vector>
using namespace std;

void fill_arrays(vector<int> & arr, int i, int val) {
    
    if(i == arr.size()) {
        return;
    }
    
    arr[i] = val;
    fill_arrays(arr, i+1, val+1);
    //backtracking step
    arr[i] = -1 * arr[i];
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n, 0);
    
    fill_arrays(v, 0, 1);
    
    for(int num : v) {
        cout<<num<<", ";
    }
    return 0;
}
