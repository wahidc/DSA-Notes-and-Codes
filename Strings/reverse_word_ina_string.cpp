#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str = "the sky is blue";

    string ans = "";
    int n = str.length();

    reverse(str.begin(), str.end());
    
    for(int i=0; i<n; i++) {
        string word = "";

        // Extract the next word from the reversed string.
        while(i<n && str[i] != ' ') {
            word += str[i];
            i++;
        }
        // Reverse the extracted word to restore its original order.
        reverse(word.begin(), word.end());
        // Append the word to the answer string.
        if(word.length()>0) {
            ans += " " + word;
        }
    }
    cout << ans.substr(1) << endl;
    return 0;
}