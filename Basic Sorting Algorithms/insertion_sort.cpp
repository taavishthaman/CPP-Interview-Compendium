#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> & arr) {
    int n = arr.size();
    
    for(int i=1; i <= n-1; i++) {
        int prev = i-1;
        int current = arr[i];
        
        while(prev >= 0 && arr[prev] > current) {
            arr[prev+1] = arr[prev];
            prev--;
        }
        
        arr[prev+1] = current;
    }
}

int main()
{
    vector<int> arr = {-2,3,4,-1,5,-12,6,1,3};
    insertion_sort(arr);
    for(int num : arr) {
        cout<<num<<", ";
    }

    return 0;
}
