#include<iostream>
using namespace std;

int first_occ(int arr[], int n, int key) {
    if(n == 0) {
        return -1;
    }
    
    if(arr[0] == key) {
        return 0;
    }
    
    int sub_index = first_occ(arr+1, n-1, key);
    if(sub_index != -1) {
        return sub_index + 1;
    }
    return -1;
}

int main() {
    int arr[] = {1,3,5,7,6,2,11,21};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cin>>key;
    cout<<first_occ(arr, n, key)<<endl;
}