/*
Sum Palindrome

Given a number, reverse it and add it to itself unless it becomes a palindrome or number of iterations becomes more than 5.

Example 1:

Input: n = 23
Output: 55 
Explanation: reverse(23) = 32,then 32+23
= 55 which is a palindrome. 

Example 2:

Input: n = 30
Output: 33
Explanation: reverse(30) = 3,then 3+30
= 33 which is palindrome. 

Your Task:  
You dont need to read input or print anything. Complete the function isSumPalindrome() which takes n as input parameter and returns that palindrome number if it becomes a palindrome else returns -1.

Expected Time Complexity: O(n*k),where k<=5.
Expected Auxiliary Space: O(1)

Constraints:
1<= n <=104
*/

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    // reverse a number
    long long reverseNumber(long long n)
    {
        long long temp=n;
        long long rev=0;
        while(temp>0)
        {
            long long  rem=temp%10;
            rev=rev*10+rem;
            temp/=10;
        }
        return rev;
    }
    
    // to check number if palindrome or not
    int isPalindrome(long long n)
    {
        long long rev=reverseNumber(n);
        return (n==rev)?1:0;
    }
    
    long long isSumPalindrome(long long n){
        // code here
        if(isPalindrome(n))
        {
            return n;
        }
        else
        {
            for(int i=0;i<5;i++)
            {
                long long m=reverseNumber(n);
                n=n+m;
                if(isPalindrome(n))
                {
                    return n;
                }
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution ob;
        cout<<ob.isSumPalindrome(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


// Question link -- https://practice.geeksforgeeks.org/problems/sum-palindrome3857/1