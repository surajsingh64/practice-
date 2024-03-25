#include <iostream>
using namespace std;

int sumofdigits(int n) {
    if (n == 0)
        return 0;
    else
        return (n % 10) + sumofdigits(n / 10);
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    cout << "Sum of digits of " << num << " is " << sumofdigits(num) << endl;
    return 0;
}
