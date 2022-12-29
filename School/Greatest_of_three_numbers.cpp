//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int greatestOfThree(int A, int B, int C) {
        // code here
        if(A>=B && A>=C)
        {
            return A;
        }
        else if(B>=A && B>=C)
        {
            return B;
        }
        else if(C>A && C>B)
        {
            return C;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int A, B, C;
        cin >> A >> B >> C;
        Solution ob;
        cout << ob.greatestOfThree(A, B, C) << "\n";
    }
}

// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/greatest-of-three-numbers2520/1?page=2&difficulty[]=-2&status[]=solved&sortBy=submissions