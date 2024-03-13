#include <iostream>
using namespace std;
int arr_sum(int arr[], int n, int id) {
    if (id == n)
        return 0;
    return arr[id] + arr_sum(arr, n, id + 1);
}
int main() 
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
       int arr[size];
    for (int i = 0; i < size; ++i) {
    	cout << "Enter " << i << " elements of the array:" << endl;
        cin >> arr[i];
    }
    int sum = arr_sum(arr, size, 0);
    cout << "Sum of array: " << sum << endl;
	return 0;
}

