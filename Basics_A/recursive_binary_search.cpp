#include <iostream>
using namespace std;

int recursive_binary_search(int arr[], int first, int last, int target){
    if (first <= last) {
        int midpoint = first + (last - first) / 2;
        
        if (arr[midpoint] == target){
            return midpoint;
        } else if (arr[midpoint] < target){
            first = midpoint + 1;
            return recursive_binary_search(arr, first, last, target);
        } else {
            last = midpoint - 1;
            return recursive_binary_search(arr, first, last, target);
        }
    } else return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int last = (sizeof(arr) / sizeof(arr[0])) - 1;

    int result = recursive_binary_search(arr, 0, last, 6);
    if (result != -1) cout << "Element found at index: " << result << endl;
    else cout << "Element not found in list." << endl;

    result = recursive_binary_search(arr, 0, last, 12);
    if (result != -1) cout << "Element found at index: " << result << endl;
    else cout << "Element not found in list." << endl;

    return 0;
}