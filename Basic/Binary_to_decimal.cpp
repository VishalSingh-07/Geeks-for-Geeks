/*
Binary number to decimal number

Given a Binary Number B, find its decimal equivalent.
 

Example 1:

Input: B = 10001000
Output: 136


Example 2:

Input: B = 101100
Output: 44
 

Your Task:
- You don't need to read or print anything. Your task is to complete the function binary_to_decimal() which takes the binary number as string input parameter and returns its decimal equivalent.
 

Expected Time Complexity: O(K * Log(K)) where K is number of bits in binary number.
Expected Space Complexity: O(1)
 
Constraints:
- 1 <= number of bits in binary number  <= 16
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int binary_to_decimal(string str) {
        // Code here.
        int n=str.size();
        int base=1;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(str[i]=='1'){
                ans+=base;
            }
            base *= 2;
        }
        return ans;
    }
};



// OR

class Solution {
  public:
    int binary_to_decimal(string str) {
        // Code here.
        int n=str.size();
        int x=0,decimal=0;
        for(int i=n-1;i>=0;i--){
            decimal+=(str[i]-'0')*pow(2,x++);
        }
        return decimal;
    }
};




//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.binary_to_decimal(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/binary-number-to-decimal-number3525/1