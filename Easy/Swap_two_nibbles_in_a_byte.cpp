/*
Swap two nibbles in a byte

Given a number n, Your task is to swap the two nibbles and find the resulting number. 

A nibble is a four-bit aggregation, or half an octet. There are two nibbles in a byte. For example, the decimal number 150 is represented as 10010110 in an 8-bit byte. This byte can be divided into two nibbles: 1001 and 0110.

Example 1:

Input: n = 100
Output: 70
Explanation: 100 in binary is 01100100, two nibbles are (0110) and (0100). If we swap the two nibbles, we get 01000110 which is 70 in decimal.



Example 2:

Input: n = 129
Output: 24
Explanation: 129 in binary is 10000001, two nibbles are (1000) and (0001). If we swap the two nibbles, we get 00011000 which is 24 in decimal.


Your Task:
- You don't need to read input or print anything. Your task is to complete the function swapNibbles() which takes an integer n as input parameter and returns an integer after swapping nibbles in the binary representation of n.

Expected Time Complexity: O(1)
Expected Space Complexity: O(1)

Constraints:
- 0 ≤ n ≤ 255
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/*
Intuition

The problem requires swapping the two nibbles in an 8-bit byte. 
A nibble consists of 4 bits, and an 8-bit byte consists of two nibbles. 
To achieve the swap, we can use bitwise/arithmetic operations to shift and combine the nibbles.



Approach

1. Modulo Operation: To get the first 4 bit of the number,we can use Number%16 
to get the first 4 bit (first nibble).

2. Divide Operation: To get the first 4 bit of the number,we can use Number/16 to 
get the last 4 bits(second nibble).

3. Combining Results: Finally, we use the reverse multiple operation to combine 
the results of the  nibbles to get the final number with swapped nibbles.



Why 16?

1. Nibble Definition:
    - A byte consists of 8 bits.
    - A nibble is 4 bits, which is half of a byte.


2. Hexadecimal and Binary Relationship:
    - A single hexadecimal digit can represent 4 bits.
    - The range of values for 4 bits (one nibble) is 0 to 15 in decimal, which is 0 to F in hexadecimal.


3. Swapping Nibbles:
    - When you swap the nibbles in a byte, you move the lower nibble to the 
        higher nibble's position and the higher nibble to the lower nibble's position.
    - For example, if the original byte is represented as AB in hexadecimal, 
        where A is the higher nibble and B is the lower nibble, after swapping, it becomes BA.

4. Mathematical Operations for Swapping:

    - To extract the lower nibble, you use the modulo operation with 16 (n % 16). 
        This is because the lower nibble can only have values from 0 to 15 (0x0 to 0xF).
        
    - To extract the higher nibble, you use integer division by 16 (n / 16). 
    This shifts the higher nibble into the lower nibble's place by effectively right-shifting the byte by 4 bits.

5. Combining the Nibbles:
    - To place the lower nibble in the higher nibble's position, you multiply it 
        by 16 (first * 16). This shifts it left by 4 bits.
    - Adding the original higher nibble (now in the lower position) gives you 
        the final byte with the nibbles swapped.

*/


// Optimized Approach
// Time complexity -> O(1) and Space -> O(1)
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        int first=n%16;
        int second=n/16;
        return first*16+second;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Question link -- https://www.geeksforgeeks.org/problems/swap-two-nibbles-in-a-byte0446/1