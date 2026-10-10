/*==========================================================
PROBLEM: Remove All Occurrences of a Substring
============================================================

Given two strings s and part, repeatedly remove the leftmost
occurrence of part from s until part no longer exists in s.

Return the final string.

Example 1:
Input:
s = "daabcbaabcbc"
part = "abc"

Output:
"dab"

Explanation:
"daabcbaabcbc" -> "dabaabcbc"
"dabaabcbc"    -> "dababc"
"dababc"       -> "dab"

Example 2:
Input:
s = "axxxxyyyyb"
part = "xy"

Output:
"ab"

============================================================
APPROACH: Find and Erase
============================================================

1. Search for part inside s using s.find(part).
2. If part is found, remove it using s.erase().
3. Repeat until part no longer exists.
4. Return the remaining string.

IMPORTANT:
We must remove the LEFTMOST occurrence each time.
find() automatically returns the first occurrence.

============================================================
CODE: STANDALONE C++ PROGRAM (VS CODE)
============================================================*/

#include <bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part) {

    // Continue while s is non-empty and part exists in s.
    while (s.length() > 0 && s.find(part) < s.length()) {

        // Find the leftmost occurrence of part.
        int pos = s.find(part);

        // Remove part starting at pos.
        // The number of characters removed is part.length().
        s.erase(pos, part.length());
    }

    // Return the string after all occurrences are removed.
    return s;
}

int main() {

    string s, part;

    // Input strings without spaces.
    cout << "Enter the main string: ";
    cin >> s;

    cout << "Enter the substring to remove: ";
    cin >> part;

    cout << "Final string: " << removeOccurrences(s, part) << endl;

    return 0;
}

/*
============================================================
REVISION NOTES
============================================================

1. s.find(part)
   - Searches for part inside s.
   - Returns the index of the first occurrence.
   - Returns string::npos if part is not found.

2. Why use s.find(part) < s.length()?
   - If found, the returned index is less than s.length().
   - If not found, string::npos is returned.
   - The clearer alternative is:
       s.find(part) != string::npos

3. s.erase(pos, length)
   - Removes 'length' characters starting at index 'pos'.
   - Example:
       s = "abcdef"
       s.erase(2, 3)
       Result: "abf"

4. Why use a while loop?
   - Removing one occurrence may create another occurrence.
   - Therefore, we must keep searching until none remains.

5. Why remove the leftmost occurrence?
   - find() returns the first occurrence from the beginning.
   - This matches the problem requirement.

6. Input limitation:
   - cin >> s does not accept spaces.
   - Use getline() if the problem requires strings with spaces.

7. Complexity:
   - find() and erase() can each take O(n) time.
   - Repeated operations can lead to O(n * m) or worse,
     depending on the string sizes and implementation.
   - Auxiliary space: O(n) for the mutable string.

============================================================*/