//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Brute Force Approach
// Time Complexity --> O(n/2) and Space --> O(1)
// class Solution {
//   public:
//     int isPerfectNumber(long long n) {
//         // code here
//         long long temp=n;
//         long long sum=0;
//         if(n<=0)
//         {
//             return false;
//         }
//         for(int i=1;i<=n/2;i++)
//         {
//             if(n%i==0)
//             {
//                 sum+=i;
//             }
//         }
//         return (temp==sum)?1:0;
//     }
// };

// Above code give Time limit Exceeded

// Optimized Solution
// Time Complexity --> O(sqrt(n)) and Space --> O(1)
class Solution {
  public:
    int isPerfectNumber(long long n) {
        // code here
        long long temp=n;
        long long sum=1;
        if(n==1)
        {
            return 0;
        }
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                sum+=i+n/i;
            }
        }
        return (temp==sum)?1:0;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/perfect-numbers3207/1