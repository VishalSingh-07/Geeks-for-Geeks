//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string revStr(string S) {
        // code here
        int n=S.length();
        for(int i=0;i<n/2;i++)
        {
            swap(S[i],S[n-i-1]);
        }
        return S;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.revStr(S) << endl;
    }
    return 0;
}

// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/java-reverse-a-string0416/1?page=1&difficulty[]=-2&status[]=solved&category[]=Strings&sortBy=submissions