#include <iostream>
#include <string.h>
using namespace std;

int main() {
    // A string is a sequence of characters used to store and manipulate text, such as names, words, sentences, and passwords.

    // In C++, there are two main ways to work with strings:
    // 1. C-style strings — character arrays ending with the null character '\0'.
    // 2. C++ strings — the string class from the <string> header. (easier & safer)

    // C-style : Character Arrays
    char character_array[] = {'a', 'b', 'c', '\0'};
    cout << character_array << endl;
    cout << strlen(character_array) << endl;
        // Input and Output in Character Array
    char str_2[6];
            // using 'cin << str_2;' can take only one word cause spcae terminates.
    cin.getline(str_2, 6);  // (str, len, delim?)
    for(char ch : str_2) {
        cout << ch << " ";
    }

    // C++ Style :
    char str[] = "Hello";       // string literals
    cout << str << endl;
    cout << strlen(str) << endl;

    // String in C++
    string string_3 = "wahid chowdhury";             // dynamic => runtime resize
    string string_4 = " is a SE student.";
    cout << string_3 << endl;
    cout << string_3 + string_4 << endl;            // concatenation
    cout << (string_3 == string_4) << endl;         // comparision
    cout << string_3.length() << endl;              // length of string
    cout << string_3.empty() << endl;               // check if string is empty
    string_4.clear();                               // clear the string
    cout << string_4 << endl;                       // prints an empty string
    string_3.push_back('!');                        // add a character at the end of the string
    cout << string_3 << endl;                       // add a character at the end of the string
    string_3.pop_back();                            // remove the last character of the string
    cout << string_3 << endl;                       // remove the last character of the string
    cout << string_3.append(" Hello") << endl;      // add a string at the end of the string
    string_3.insert(0, "Hello ");                   // insert a string at the beginning of the string
    cout << string_3 << endl;                       // insert a string at the beginning of the string
    string_3.erase(0, 6);                           // erase a string from the beginning of the string
    cout << string_3 << endl;                       // erase a string from the beginning of the string
    string_3.replace(0, 5, "Wahid");                // replace a string from the beginning of the string
    cout << string_3 << endl;                       // replace a string from the beginning of the string
    string_3.swap(string_4);                        // swap two strings
    cout << string_3 << endl;                       // swap two strings
    cout << string_3.substr(0, 5) << endl;          // get a substring from the string
    cout << string_3.find("Hello") << endl;         // find the position of a substring in the string
    cout << string_3.rfind("Hello") << endl;        // find the last occurrence of a substring in the string

}