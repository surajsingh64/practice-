#include <iostream>
using namespace std;

void lower_triangle_matrix(int matrix[][3], int n) {
    cout << "Lower Triangle Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j <= i)
                cout << matrix[i][j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    lower_triangle_matrix(matrix, 3);
    return 0;
}

