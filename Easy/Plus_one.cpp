//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// Brute Force Approach
// class Solution {
//   public:
//     vector<int> increment(vector<int> arr ,int n) {
//         // code here
//         vector<int> ans;
//         long long digit=arr[0];
//         for(int i=1;i<n;i++)
//         {
//             digit=digit*10+arr[i];
//         }
//         digit=digit+1;
//         while(digit>0)
//         {
//             ans.push_back(digit%10);
//             digit/=10;
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };

// Above code ❌ is not working for below test case
// n=45
// arr=[8 4 9 8 8 9 7 7 9 4 2 5 0 2 7 9 0 4 9 7 3 9 2 9 6 5 7 8 0 9 4 9 1 9 6 8 9 3 3 4 7 8 5 4 5]

// This is because value of n hold the value in the range of  
// -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807

// Due to high digits value above code give runtime error.


// Optimized Approach
// Time complexity -> O(n) and Space --> O(1)
class Solution {
  public:
    vector<int> increment(vector<int> arr ,int n) {
        // code here
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]<9)
            {
                arr[i]++;
                return arr;
            }
            else if(arr[i]==9)
            {
                arr[i]=0;
            }
        }
        arr.push_back(0);
        arr[0]=1;
        
        return arr;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/plus-one/1

//  My Solution link -- https://leetcode.com/problems/plus-one/solutions/3189991/easy-c-solution-optimized-approach-time-complexity-o-n-and-space-complexity-o-1/

// Video Link -- https://youtu.be/Tcxob-LyBTo