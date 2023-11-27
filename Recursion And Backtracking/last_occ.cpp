#include<iostream>
using namespace std;

int last_occ(int arr[], int n, int key) {
    if(n == 0) {
        return -1;
    }
    
    int sub_index = last_occ(arr+1, n-1, key);
    
    if(sub_index == -1) {
        if(arr[0] == key) {
            return 0;
        }
        return -1;
    } else {
        return 1 + sub_index;
    }
}

int main() {
    int arr[] = {1,3,5,7,6,2,7,11,21};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cin>>key;
    cout<<last_occ(arr, n, key)<<endl;
}