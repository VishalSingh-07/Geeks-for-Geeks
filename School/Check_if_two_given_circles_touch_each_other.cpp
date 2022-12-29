//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int circleTouch(int X1, int Y1, int R1, int X2, int Y2, int R2) {
        // code here
        double d= sqrt(pow(X2-X1,2) + pow(Y2-Y1,2) );
        
        if(d <= (R1 + R2))
        {
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int X1, Y1, R1, X2, Y2, R2;
        cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;
        Solution ob;
        cout << ob.circleTouch(X1, Y1, R1, X2, Y2, R2) << "\n";
    }
}

// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/checcheck-if-two-given-circles-touch-each-other5038/1?page=3&difficulty[]=-2&status[]=solved&sortBy=submissions