#include <iostream>
#include <string>
using namespace std;
void reverse(string& str, int st, int d) {
    if (st >= d)
        return;   
    char temp = str[st];
    str[st] = str[d];
    str[d] = temp;
    reverse(str, st + 1,d - 1);
}
int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    reverse(str, 0, str.length() - 1);
    cout << "Reversed string is: " << str << endl;
    return 0;
}
