//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // Time complexity --> O(n^2)
    // int getPairsCount(int arr[], int n, int k) {
    //     // code here
    //     int count=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(arr[i]+arr[j]==k)
    //             {
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
        
    // }
    
    // Time complexity --> O(n)
    int getPairsCount(int arr[], int n, int k) {
        // code here
        map<int,int> m;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(k-arr[i]>0)
            {
                count=count+m[k-arr[i]];
                m[arr[i]]++;
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
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1?page=1&difficulty[]=0&status[]=solved&category[]=Arrays&sortBy=submissions