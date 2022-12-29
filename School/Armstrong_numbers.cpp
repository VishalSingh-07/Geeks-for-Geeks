//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        int temp=n;
        int result,module;
        while(temp>0)
        {
            module=temp%10;
            result= result+ (module*module*module);
            temp=temp/10;
            
        }
        if(n == result)
        {
            return "Yes";
        }
        else
        {
            return "No";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends

// Question Link --- https://practice.geeksforgeeks.org/problems/armstrong-numbers2727/1?page=1&difficulty[]=-2&status[]=solved&sortBy=submissions