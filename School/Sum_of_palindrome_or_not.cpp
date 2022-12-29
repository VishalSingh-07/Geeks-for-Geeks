//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isDigitSumPalindrome(int N) {
        // code here
        int sum=0,r;
        while(N>0)
        {
            sum=sum+N%10;
            N=N/10;
        }
        int temp=sum;
        int palindromesum=0;
        while(sum>0)
        {
            r=sum%10;
            palindromesum=(palindromesum*10)+r;
            sum=sum/10;
            
        }
        if(temp==palindromesum)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isDigitSumPalindrome(N) << "\n";
    }
}

// } Driver Code Ends

// Question Link --- https://practice.geeksforgeeks.org/problems/sum-of-digit-is-pallindrome-or-not2751/1?page=1&difficulty[]=-2&status[]=solved&sortBy=submissions