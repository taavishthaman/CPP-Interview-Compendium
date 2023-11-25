#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int> & arr) {
    int n = arr.size();
    
    for(int i=0; i<=n-2; i++) {
        int min_index = i;
        for(int j=i+1; j<=n-1; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        swap(arr[min_index], arr[i]);
    }
}

int main()
{
    vector<int> arr = {-2,3,4,-1,5,-12,6,1,3};
    selection_sort(arr);
    for(int num : arr) {
        cout<<num<<", ";
    }

    return 0;
}
