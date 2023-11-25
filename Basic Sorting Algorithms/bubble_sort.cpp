#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int> & arr) {
    int n = arr.size();
    
    for(int times=1; times <= n-1; times++) {
        for(int j=0; j<=n-1-times; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main()
{
    vector<int> arr = {-2,3,4,-1,5,-12,6,1,3};
    bubble_sort(arr);
    for(int num : arr) {
        cout<<num<<", ";
    }

    return 0;
}
