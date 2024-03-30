#include<iostream>
using namespace std;

int linearsearch(int ar[], int sizes, int keys) {
    for(int i = 0; i < sizes; i++) {
        if (ar[i] == keys)
            return i;
    }
    return -1; 
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

    int index = linearsearch(arr, size, key);
    if (index != -1) {
        cout << "Key found at index: " << index << endl;
    } 
    else
    {
        cout << "Key not found." << endl;
    }

    return 0;
}
