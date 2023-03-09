//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
// class Solution {
//   public:
//     // Function to return the position of the first repeating element.
//     int firstRepeated(int arr[], int n) {
//         // code here
//         for(int i=0;i<n;i++)
//         {
//             int count=0;
//             for(int j=0;j<n;j++)
//             {
//                 if(arr[i]==arr[j])
//                 {
//                     count++;
//                 }
//             }
//             if(count>1)
//             {
//                 return i+1;
//             }
//         }
//         return -1;
//     }
// };

// Above Code ❌ give time limit exceeded due to high complexity -> O(n^2)

// Optimized Force Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[arr[i]]>1)
            {
                return i+1;
            }
        }
        return -1;
    }
};




//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

// } Driver Code Ends


// Question link -- https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1