//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string toLower(string S) {
        // code here
        transform(S.begin(),S.end(), S.begin(), ::tolower);
        return S;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.toLower(S) << endl;
    }
    return 0;
}

// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/java-convert-string-to-lowercase2313/1?page=1&difficulty[]=-2&status[]=solved&category[]=Strings&sortBy=submissions