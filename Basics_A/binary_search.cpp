#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int target){
    int first = 0;
    int last = size - 1;

    while (first <= last) {
        int midpoint = first + (last - first) / 2;

        if (arr[midpoint] == target) {
            return midpoint;
        } else if (arr[midpoint] > target) {
            last = midpoint -1;
        } else {
            first = midpoint + 1;
        }
    }

    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = binary_search(arr, size, 6);
    if (result != -1) cout << "Element found at index: " << result << endl;
    else cout << "Element not found in list." << endl;

    result = binary_search(arr, size, 12);
    if (result != -1) cout << "Element found at index: " << result << endl;
    else cout << "Element not found in list." << endl;

    return 0;
}