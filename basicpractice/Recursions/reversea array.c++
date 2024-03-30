#include<iostream>
using namespace std;

void reversearr(int arr[], int rarr[], int n, int s) {
    if (n == 0) 
        return;
    rarr[s] = arr[n - 1]; 
    reversearr(arr, rarr, n - 1, s + 1); 
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

    int s = 0;
    int rarr[size];
    reversearr(arr, rarr, size, s);

    cout << "Reversed array: ";
    for(int i = 0; i < size; i++) {
        cout << rarr[i] << " ";
    }
    cout << endl;

    return 0;
}
