//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
    int cppIntType() {
        // code here
        int x;
        cin>>x;
        return x;
    }
    
    char cppCharType() {
        // code here
         char x;
        cin>>x;
        return x;
    }
    
    string cppFloatType() {
        // code here
        string x;
        cin>>x;
        return x;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        Solution ob;
        cout << ob.cppIntType() << endl;
        cout << ob.cppCharType() << endl;
        cout << ob.cppFloatType() << endl;
    }
    return 0;
}
// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/c-data-types1523/1?page=3&difficulty[]=-2&status[]=solved&sortBy=submissions