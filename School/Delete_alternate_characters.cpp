//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// Brute Force Approach
// Time complexity --> O(n) and Space --> O(n)
// class Solution {
//   public:
//     string delAlternate(string S) {
//         // code here
//         string ans;
//         for(int i=0;i<S.length();i++)
//         {
//             if(i%2!=0)
//             {
//                 continue;
//             }
//             else
//             {
//                 ans.push_back(S[i]);
//             }
//         }
//         return ans;
//     }
// };



// Optimized Approach

// Time complexity --> O(n) and Space --> O(1)
class Solution {
  public:
    string delAlternate(string S) {
        // code here
        int i;
        for(i=0;i<S.length();i++)
        {
          if(i%2==0)
	       {
	        cout<<S.at(i);
	       }
        }
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
        cout << ob.delAlternate(S) << endl;
    }
    return 0;
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/java-delete-alternate-characters4036/1