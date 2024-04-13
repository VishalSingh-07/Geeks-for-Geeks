/*
Reverse Bits

Given a number x, reverse its binary form and return the answer in decimal.

Example 1:

Input:
x = 1
Output:
2147483648 
Explanation:
Binary of 1 in 32 bits representation-
00000000000000000000000000000001
Reversing the binary form we get, 
10000000000000000000000000000000,
whose decimal value is 2147483648.


Example 2:

Input:
x = 5
Output:
2684354560 
Explanation:
Binary of 5 in 32 bits representation-
00000000000000000000000000000101
Reversing the binary form we get, 
10100000000000000000000000000000,
whose decimal value is 2684354560.


Your Task:
- You don't need to read input or print anything. Your task is to complete the function reversedBits() which takes an Integer x as input and returns the reverse binary form of x in decimal form.

Expected Time Complexity: O(log (x))
Expected Auxiliary Space: O(1)

Constraints:
0  <=  x  <  232
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// Brute Force Approach
// Time complexity -> O(log(x)) and Space -> O(log(x))
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        
        // Convert x to binary representation
        string binary="";
        while(x>0){
          binary=to_string(x%2)+binary;
          x/=2;
        }
        int j=binary.size()-1;
        string ans="";
        
        // Reverse the binary representation to ensure it's 32 bits long
        for(int i=0;i<32;i++){
            if(j>=0){
                ans+=binary[j--];
            }else{
                ans+="0";
            }
        }
        
        // Convert the reversed binary representation back to decimal 
        long long decimal=0;
        for(int i=ans.size()-1;i>=0;i--){
          decimal += pow(2, ans.size() - 1 - i) * (ans[i] - '0');
        }
        return decimal;
    }
};


// Optimized Approach
// Time complexity -> O(log(x)) and Space -> O(1)
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        long long ans=0;
        int i=0;
        while(x>0){
          if(x%2!=0){
              ans+=pow(2,32-1-i);
          }
          x/=2;
          i++;
        }
        return ans;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/reverse-bits3556/1