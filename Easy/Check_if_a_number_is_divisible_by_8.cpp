/*
Check if a number is divisible by 8

Given a string representation of a decimal number s, check whether it is divisible by 8.

Example 1:

Input:
s = "16"
Output:
1
Explanation:
The given number is divisible by 8,
so the driver code prints 1 as the output.


Example 2:

Input:
s = "54141111648421214584416464555"
Output:
-1
Explanation:
Given Number is not divisible by 8, 
so the driver code prints -1 as the output.


Your Task:
You don't need to read input or print anything.Your task is to complete the function DivisibleByEight() which takes a string s as the input and returns 1 if the number is divisible by 8, else it returns -1.

Expected Time Complexity: O(1).
Expected Auxillary Space: O(1).

Constraints:
1 <= |s| <= 106

*/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends



// Hint - A number is divisible by 8 if the last 3 digit is divisible by 8.

// Optimized Approach
// Time complexity -> O(1) and Space -> O(1)
class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        int n=s.size();
        if(n<=3)
        {
            return stoi(s)%8==0?1:-1;
        }
        return stoi(s.substr(n-3))%8==0?1:-1;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/check-if-a-number-is-divisible-by-83957/1
