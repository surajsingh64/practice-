#include <iostream>
using namespace std;

void countSort(int arr[], int size) 
	{
   		int maxElement = arr[0];
   		for (int i = 1; i < size; i++)
		{
        	if (arr[i] > maxElement) 
			{
            	maxElement = arr[i];
        	}
    	}

    int count[maxElement + 1] = {0};
    for (int i = 0; i < size; i++) 
	{
        count[arr[i]]++;
    }

    for (int i = 1; i <= maxElement; i++) 
	{
        count[i] += count[i - 1];
    }

    int temp[size];
    for (int i = 0; i < size; i++) 
	{
        temp[i] = arr[i];
    }

    for (int i = size - 1; i >= 0; i--) 
	{
        arr[count[temp[i]] - 1] = temp[i];
        count[temp[i]]--;
    }
}

void printarray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
	{
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " elements of the array: ";
    for (int i = 0; i < size; i++)
	{
        cin >> arr[i];
    }

    cout << "the array before sorting : ";
    printarray(arr, size);

    countSort(arr, size);

    cout << "Sorted array: ";
    printarray(arr, size);

    return 0;
}
