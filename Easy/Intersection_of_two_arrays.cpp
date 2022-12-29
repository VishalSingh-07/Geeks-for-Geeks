//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        set<int> s;
        for(int i=0;i<n;i++)
        {
            s.insert(a[i]);
        }
        int count=0;
        for(int i=0;i<m;i++)
        {
            if(s.find(b[i])!=s.end())
            {
                s.erase(b[i]);
                count++;
            }
        }
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1?page=1&difficulty[]=0&status[]=solved&category[]=Arrays&sortBy=submissions