/*
============================================================
Problem: Prime Palindrome
============================================================

Given an integer n, find the smallest prime number greater
than or equal to n that is also a palindrome.

Example:
Input:  13
Output: 101

============================================================
Approach:
1. Check whether a number is prime.
2. Check whether it is a palindrome.
3. Skip even-length numbers greater than 11.
4. Return the first number satisfying both conditions.
============================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Check whether n is prime
bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    // Check divisors only up to sqrt(n)
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

// Check whether n is a palindrome
bool isPalindrome(int n)
{
    string s = to_string(n);
    string rev = s;

    reverse(rev.begin(), rev.end());

    return s == rev;
}

// Find the smallest prime palindrome >= n
int primePalindrome(int n)
{
    while (true)
    {

        // Every even-length palindrome greater than 11
        // is divisible by 11, so skip that digit range.
        if (n > 11)
        {
            string s = to_string(n);

            if (s.length() % 2 == 0)
            {
                n = pow(10, s.length());
                continue;
            }
        }

        // The number must be both prime and a palindrome.
        if (isPalindrome(n) && isPrime(n))
        {
            return n;
        }

        n++;
    }
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Smallest prime palindrome: "
         << primePalindrome(n) << endl;

    return 0;
}

/*==========================================================
Revision Notes:
============================================================

1. isPrime():
   Checks divisors up to sqrt(n), not n - 1.

2. isPalindrome():
   Reverses the number's string and compares both strings.

3. s.length() % 2 == 0:
   True when the number has an even number of digits.

4. continue:
   Skips the remaining statements in the current loop iteration.

5. Even-length optimization:
   Every even-length palindrome is divisible by 11.
   The exception is 11 itself.

6. Example:
   Input: 13
   Output: 101

============================================================*/