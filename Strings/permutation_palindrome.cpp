/*

# PROBLEM: Permutation in String (LeetCode 567)

Given two strings s1 and s2, return true if s2 contains a
permutation of s1. Otherwise, return false.

A permutation is any rearrangement of a string's characters.

Example 1:
Input:
s1 = "ab"
s2 = "eidbaooo"

Output: true

Explanation:
"ba" is a permutation of "ab" and exists inside s2.

Example 2:
Input:
s1 = "ab"
s2 = "eidboaoo"

Output: false

Explanation:
No substring of length 2 in s2 has the same character
frequencies as s1.

1. Count the frequency of each character in s1.
2. Set the window size equal to s1.length().
3. Start a window at every index of s2.
4. Count the character frequencies inside that window.
5. Compare the window frequencies with s1's frequencies.
6. If they match, return true.
7. If no window matches, return false.

IMPORTANT:
Two strings are permutations of each other if and only if
they have the same character frequencies.

*/

#include <bits/stdc++.h>
using namespace std;

// Compare two frequency arrays.
// Return true if all 26 character counts are equal.
bool isFreqSame(int freq1[], int freq2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2)
{

    // Count the frequency of each character in s1.
    int freq[26] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i] - 'a']++;
    }

    // Every permutation of s1 has exactly this length.
    int windSize = s1.length();

    // Try starting a window at every index of s2.
    for (int i = 0; i < s2.length(); i++)
    {

        int windIdx = 0, idx = i;

        // Store the frequency of the current window.
        int windFreq[26] = {0};

        // Build a window of size windSize.
        while (windIdx < windSize && idx < s2.length())
        {

            // Count the current character.
            windFreq[s2[idx] - 'a']++;

            windIdx++;
            idx++;
        }

        // If the frequencies match, a permutation exists.
        if (isFreqSame(freq, windFreq))
        {
            return true;
        }
    }

    // No matching window was found.
    return false;
}

int main()
{

    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    if (checkInclusion(s1, s2))
    {
        cout << "Output: true" << endl;
    }
    else
    {
        cout << "Output: false" << endl;
    }

    return 0;
}
