//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    /*
    // Time complexity --> O(2^n) and O(1.6180^n) --> Golden ratio 
        long long int nthFibonacci(long long int n){
            // code here
            if(n<=1)
            {
                return n;
            }
            else
            {
                return (nthFibonacci(n-1) + nthFibonacci(n-2));
            }
            
        }
    */
    
    
    // Time complexity --> O(n)
    
    long long int nthFibonacci(long long int n){
        // code here
        if(n<=1)
        {
            return n;
        }
        long long int a=0,b=1,c;
        for(long long int i=2;i<=n;i++)
        {
            c=(a+b)%1000000007;// answer can be very large so we divided by 10^7
            a=b;
            b=c;
        }
        return c;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1?page=1&difficulty[]=0&status[]=solved&sortBy=submissions