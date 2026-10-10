#include <iostream>
#include <string>
using namespace std;

bool isAlphaNum(char c) {
    if(isalnum(c)) {
        return true;
    }
    return false;
}

bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;
    
    while(left < right) {
        if(!isAlphaNum(str[left])) {
            left++;
        } else if(!isAlphaNum(str[right])) {
            right--;
        } else {
            if(tolower(str[left]) != tolower(str[right])) {
                return false;
            }
            left++;
            right--;
        }
    }
    return true;
}

int main() {
    string str = "A man, a plan, a canal: Panama";

    if(isPalindrome(str)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    
    
    return 0;
}