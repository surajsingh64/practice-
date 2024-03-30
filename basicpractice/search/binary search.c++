#include<iostream>
using namespace std;

int binarysearch(int arr[], int size, int key) {
    int l = 0;
    int u = size - 1;
    while (l <= u) {
        int mid = (l + u) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            l = mid + 1;
        else
            u = mid - 1;
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    for(int i = 0; i < size; i++) {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key: ";
    cin >> key;

    int index = binarysearch(arr, size, key);
    if (index != -1) {
        cout << "Key found at index: " << index << endl;
    } else {
        cout << "Key not found." << endl;
    }

    return 0;
}
