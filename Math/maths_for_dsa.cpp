#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

void printDigits(int n);

// Prime number in a range
// bool isPrime(int n) {
//     if (n < 2) {
//         return false;
//     }

//     for (int i = 2; i * i <= n; i++) {
//         if (n % i == 0) {
//             return false;
//         }
//     }

//     return true;
// }
// int main() {
//     int n = 42;

//     // Print all prime numbers from 1 to n
//     cout << "Prime numbers from 1 to " << n << ": ";
//     for (int i = 1; i <= n; i++) {
//         if (isPrime(i)) {
//             cout << i << " ";
//         }
//     }
//     return 0;
// }

// But this is not the most efficient way to find prime numbers in a range.
// The Sieve of Eratosthenes is a more efficient algorithm for finding all prime numbers up to a given limit.
// Here's an implementation of the Sieve of Eratosthenes in C++:

int main() {
    int n = 42;
    int count = 0;
    // Create a boolean array "isPrime[0..n]" and initialize all entries as true.
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    for(int i=2; i<n; i++) {
        if(isPrime[i]) {
            count++;
            // i*i also works but may cause overflow.
            for(int j=i*2; j<=n; j+=i) {
                isPrime[j] = false;
            }
        }
    }

    cout << "Prime numbers from 1 to " << n << ": ";
    for(int i=1; i<=n; i++) {
        if(isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << "\nTotal prime numbers from 1 to " << n << ": " << count << endl;

    printDigits(n);
    // shortcut of the above code is to use the STL library. The STL library has a function called "is_prime" which can be used to check if a number is prime or not. The function takes an integer as input and returns a boolean value indicating whether the number is prime or not. Here's an example of how to use the "is_prime" function from the STL library:
    cout << (int)(log10(n) + 1) << endl; // number of digits in n

    // Call from main():
    // cout << reverseInteger(123);  // Output: 321
    // cout << reverseInteger(-120); // Output: -21
    return 0;



}

void printDigits(int n) {
    while(n != 0) {
        int digit = n % 10;
        cout << digit << " ";
        n /= 10;
    }
}


int reverseInteger(int x) {
    /*
    Problem: Reverse Integer (LeetCode 7)
    Reverse the digits of a signed integer.
    Return 0 if the reversed number overflows 32-bit integer range.

    Example:
    Input: 123   Output: 321
    Input: -120  Output: -21
    Input: 1534236469  Output: 0

    Approach:
    1. Extract the last digit using x % 10.
    2. Check overflow before multiplying revNum by 10.
    3. Append the digit to revNum.
    4. Remove the last digit using x /= 10.
    5. Repeat until x becomes 0.
    */

    int revNum = 0;

    while (x != 0) {
        int dig = x % 10;  // Extract last digit

        // Check 32-bit integer overflow before multiplication
        if (revNum > INT_MAX / 10 ||
            (revNum == INT_MAX / 10 && dig > 7) ||
            revNum < INT_MIN / 10 ||
            (revNum == INT_MIN / 10 && dig < -8)) {
            return 0;
        }

        revNum = (revNum * 10) + dig;  // Append digit
        x /= 10;                       // Remove last digit
    }

    return revNum;

    /*
    Revision Notes:
    - x % 10  -> extracts the last digit.
    - x /= 10 -> removes the last digit.
    - revNum * 10 shifts existing digits left.
    - Negative numbers work automatically.
    - INT_MAX = 2147483647; INT_MIN = -2147483648.
    - Time Complexity: O(log10(|x|)) — one iteration per digit.
    - Space Complexity: O(1) — constant extra space.
    */
}


