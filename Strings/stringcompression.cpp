/*
========================================================
LeetCode 443: String Compression
========================================================

PROBLEM:
Given a character array, compress consecutive repeating
characters in-place.

- Write each character once.
- If a character repeats more than once, append its count
  as individual digits.
- Return the new length of the compressed array.

Example:
Input:
7
a a b b c c c

Output:
6
Compressed array: a 2 b 2 c 3

APPROACH: TWO POINTERS + COUNTING

1. i   = Reads characters and counts consecutive duplicates.
2. idx = Writes compressed characters into the array.
3. ch  = Stores the current character.
4. count = Counts consecutive occurrences.

ALGORITHM:
1. Save arr[i] in ch.
2. Count consecutive occurrences using a while loop.
3. Write ch at arr[idx].
4. If count > 1, convert count to a string and write
   each digit separately.
5. Continue with the next group.
6. Resize the array to idx and return idx.

========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& arr) {
    int idx = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {

        char ch = arr[i];  // Current character
        int count = 0;

        // Count consecutive occurrences of ch
        while (i < n && arr[i] == ch) {
            count++;
            i++;
        }

        // Write the character once
        arr[idx++] = ch;

        // Write count only if it is greater than 1
        if (count > 1) {
            string str = to_string(count);

            // A count can contain multiple digits, e.g. 12
            for (char dig : str) {
                arr[idx++] = dig;
            }
        }

        // The for loop will increment i again.
        // Undo the extra increment to avoid skipping a group.
        i--;
    }

    // Remove unused elements from the end
    arr.resize(idx);

    return idx;
}

int main() {
    int n;
    cin >> n;

    vector<char> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int newLength = compress(arr);

    cout << newLength << "\n";

    // Display the compressed array
    for (char ch : arr) {
        cout << ch << " ";
    }
    cout << "\n";

    return 0;
}

/*
========================================================
SAMPLE INPUT:
7
a a b b c c c

SAMPLE OUTPUT:
6
a 2 b 2 c 3

========================================================
DRY RUN:

Input: a a a b b c

Group | Count | Written | idx
------+-------+---------+----
aaa   |   3   | a 3     |  2
bb    |   2   | b 2     |  4
c     |   1   | c       |  5

Final array: a 3 b 2 c
Return: 5

========================================================
IMPORTANT CONCEPTS:

1. TWO POINTERS
   i   -> Reads and counts characters.
   idx -> Writes compressed characters.

2. to_string(count)
   Converts an integer into a string.
   Example: 12 -> "12"

3. RANGE-BASED FOR LOOP
   for (char dig : str)
   Visits every digit in the count string.

4. i--
   The while loop advances i past the current group.
   i-- compensates for the outer for loop's increment.
   Without it, the next group may be skipped.

5. IN-PLACE MODIFICATION
   The compressed result overwrites the original array.
   idx always tracks the next writing position.

6. EDGE CASES
   - Single character: a -> a
   - Repeated characters: a a a -> a 3
   - Multi-digit count: 12 a's -> a 1 2
   - All characters distinct: a b c -> a b c

========================================================
COMPLEXITY:

Time: O(n)
Each character is processed a constant number of times.

Auxiliary space: O(log n) in the strict analysis,
because the count string can contain O(log n) digits.
The algorithm otherwise modifies the array in-place.

========================================================
REVISION CHECKLIST:

[ ] Understand the roles of i and idx.
[ ] Explain why i-- is necessary.
[ ] Know why count == 1 needs no digit.
[ ] Know why to_string() is used.
[ ] Remember that counts may have multiple digits.
[ ] Return the compressed length, not the original length.

========================================================
*/