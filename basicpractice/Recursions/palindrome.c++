#include<iostream>
using namespace std;

// Function to check if a string is palindrome
bool palindrome(string S, int i, int j) {
    if (i >= j)
        return true;
    if (S[i] != S[j])
        return false;
    return palindrome(S, i + 1, j - 1);
}

int main() {
    string St;
    cout << "Enter a string: ";
    cin >> St;

    if (palindrome(St, 0, St.length() - 1)) {
        cout << "The word is a palindrome";
    } else {
        cout << "The word is not a palindrome";
    }    
    return 0;
}
