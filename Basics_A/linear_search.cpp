#include <iostream>
using namespace std;

int linear_search(int arr[], int size, int target){
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
} 

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = linear_search(arr, size, 6);
    if (result != -1) cout << "Element found at index: " << result << endl;
    else cout << "Element not found in list." << endl;

    result = linear_search(arr, size, 12);
    if (result != -1) cout << "Element found at index: " << result << endl;
    else cout << "Element not found in list." << endl;

    return 0;
}