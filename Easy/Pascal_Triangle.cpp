//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
// Time complexity --> O(n^2) and space --> O(n^2)
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector<ll> result(n,0);
        result[0]=1;
        ll m=pow(10,9)+7;
        for(ll i=1;i<n;i++)
        {
            for(ll j=i;j>=1;j--)
            {
                result[j]=(result[j]+result[j-1])%m;
            }
        }
        return result;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends


// Question link --> https://practice.geeksforgeeks.org/problems/pascal-triangle0652/0

// Dry run --> https://leetcode.com/problems/pascals-triangle-ii/solutions/2938432/easy-solution-with-the-written-dry-run-photo/