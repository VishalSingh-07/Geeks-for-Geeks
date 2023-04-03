/*
Remainder on dividing by 11

Given a big positive number x represented as string, find value of x % 11 or x mod 11. Output is expected as an integer.

Example 1:

Input: x = 1345
Output: 3
Explanation: 1345 % 11 = 3 


Example 2:

Input: x = 231456786543567898765
Output: 1
Explanation: 231456786543567898765 % 11 = 1

Your Task:  
You don't need to read input or print anything. Your task is to complete the function xmod11() which takes string x as the input parameter and returns the integer value of x%11.

Expected Time Complexity: O(length of string x)
Expected Space Complexity: O(1)

Constraints:
1 ≤ length of string x ≤ 100000
*/
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
// where n= length of string

class Solution
{

public:
    int xmod11(string x)
    {
      // code here
      int n=x.length();
      int r=0;
      for(int i=0;i<n;i++)
      {
          int num=r*10+(int)(x[i]-'0');
          r=num%11;
      }
      return r;
    }
};




//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends

/*
1. Question link -- https://practice.geeksforgeeks.org/problems/aa8c89caad6b5c3a76ba5e6d65454f77aac3f3543526/1

2. Video link -- https://youtu.be/xREnKnumr9M
*/