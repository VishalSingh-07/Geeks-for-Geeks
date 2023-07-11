//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
// class Solution{
// public:
//     vector<int> findTwoElement(vector<int> arr, int n) {
//         // code here
//         int repeating=-1,missing=-1;
//         for(int i=1;i<=n;i++)
//         {
//             int count=0;
//             for(int j=0;j<n;j++)
//             {
//                 if(arr[j]==i)
//                 {
//                     count++;
//                 }
//             }
//             if(count==2)
//             {
//                 repeating=i;
//             }
//             if(count==0)
//             {
//                 missing=i;
//             }
//             if(repeating!=-1 && missing!=-1)
//             {
//                 break;
//             }
//         }
//         return {repeating,missing};
//     }
// };

// Above code give time limit Exceeded due to time complexity O(n^2)

// Better Approach
// Time complexity -> O(2n) and Space -> O(n)
// class Solution{
// public:
//     vector<int> findTwoElement(vector<int> arr, int n) {
//         // code here
//         int hash[n+1]={0};
//         for(int i=0;i<n;i++)
//         {
//             hash[arr[i]]++;
//         }
//         int repeating=-1,missing=-1;
//         for(int i=1;i<=n;i++)
//         {
//             if(hash[i]==2)
//             {
//                 repeating=i;
//             }
//             if(hash[i]==0)
//             {
//                 missing=i;
//             }
//             if(repeating!=-1 && missing!=-1)
//             {
//                 break;
//             }
//         }
//         return {repeating,missing};
//     }
// };


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        
        // S - SN 
        // S2 - S2N
        long long len=arr.size();
        long long SN=(len * (len + 1))/2;
        long long S2N=(len * (len + 1) * (2 * len + 1)) / 6;
        
        long long S=0,S2=0;
        for(int i=0;i<len;i++)
        {
            S+=(long long)arr[i];
            S2+=(long long)arr[i] * (long long)arr[i];
        }
        
        long long val1=S-SN; // S-Sn = X-Y
        
        long long val2=S2-S2N; // S2-S2n = X^2-Y^2
        val2=val2/val1; // x + y
        
        long long x=(val1+val2)/2; // repeating number
        
        long long y=x-val1;
        
        return {(int)x,(int)y};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends

/*
1. Question link -- https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

2. Video link -- https://youtu.be/2D0D8HE6uak
*/