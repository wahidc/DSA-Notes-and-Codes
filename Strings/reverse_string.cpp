#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;


int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Reversed string: ";

    // Character array method
    int st = 0, end = str.length() - 1;
    while (st < end) {
        swap(str[st], str[end]);
        st++;
        end--;
    }
    cout << str << endl;

    // C++ string method
    string reversed_str = str;
    reverse(reversed_str.begin(), reversed_str.end());
    cout << reversed_str << endl;
}