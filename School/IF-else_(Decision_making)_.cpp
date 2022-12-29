//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string compareNM(int n, int m){
        // code here
        if(n>m)
        {
            cout<<"greater";
        }
        else if(n<m)
        {
            cout<<"lesser";
        }
        else
        {
            cout<<"equal";
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m ; cin>>n>>m;
        Solution obj;
        cout<<obj.compareNM(n,m)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/java-if-else-decision-making0924/1?page=2&difficulty[]=-2&status[]=solved&sortBy=submissions