#include<iostream>
using namespace std;

int is_sorted(int arr[], int n) {
    //If no elements or only one element remain
    if(n == 0 || n == 1) {
        return true;
    }
    
    if(arr[0] < arr[1] && is_sorted(arr+1, n-1)) {
        return true;
    }
    
    return false;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(int);
    cout<<is_sorted(arr, n)<<endl;
}