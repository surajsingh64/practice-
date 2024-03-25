#include <iostream>
using namespace std;
int arrsum(int arr[], int size) {
    if (size == 0)
        return 0;
    return arr[size - 1] + arrsum(arr, size - 1);
}
int main() {
    int arr[] = {5, 3, 8, 1, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum of all elements in the array is: " << arrsum(arr, size) << endl;
    return 0;
}
