//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int fact(int n)
    {
        int f=1;
        for(int i=1;i<=n;i++)
        {
            f=f*i;
        }
        return f;
    }
    int isPerfect(int N) {
        // code here
        int n=N;
        int sum=0;
        while(N!=0)
        {
            sum=sum+fact(N%10);
            N=N/10;
        }
        return n==sum;
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
        cout << ob.isPerfect(N) << "\n";
    }
}

// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/perfect-number3759/1?page=3&difficulty[]=-2&status[]=solved&sortBy=submissions