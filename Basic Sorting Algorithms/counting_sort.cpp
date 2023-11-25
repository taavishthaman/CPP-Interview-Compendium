#include <iostream>
#include <vector>
using namespace std;

void counting_sort(vector<int> & arr) {
    int largest = 0;
    for(int num : arr) {
        largest = max(largest, num);
    }
    
    vector<int> freq(largest+1, 0);
    
    for(int num : arr) {
        freq[num]++;
    }
    
    int j = 0;
    for(int i=0; i<freq.size(); i++) {
        while(freq[i] > 0) {
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }
}

int main()
{
    vector<int> arr = {88, 97, 10, 12, 15, 1, 5, 6, 12, 5, 8};
    counting_sort(arr);
    for(int num : arr) {
        cout<<num<<", ";
    }

    return 0;
}
