#include <iostream>
using namespace std;

void counting_sort(int A[], int n, int k) {
    int C[k + 1] = {0}; 
	int B[n];
   
    for (int j = 0; j < n; ++j)
        C[A[j]]++;
    
    for (int i = 1; i <= k; ++i)
        C[i] += C[i - 1];
  
    for (int j = n - 1; j >= 0; --j) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
    
    for (int j = 0; j < n; ++j)
        A[j] = B[j];
}
int main() {
    int A[] = {6, 50, 20, 90, 60, 30, 2};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 90;
    counting_sort(A, n, k);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}

