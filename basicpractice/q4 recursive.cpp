#include <iostream>
using namespace std;

void f(int n) {
    if (n >= 1) {
        if (n % 2 == 0) {
            cout << n * n * n << endl;
        }
        f(n - 1);
    }
}

int main() {
    f(10); // Example usage
    return 0;
}

