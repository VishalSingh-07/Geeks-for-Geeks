//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


// Time complexity --> O(n)
// class Solution{   
// public:
//     int countZeroes(int arr[], int n) {
//         // code here
//         int count=0;
//         for(int i=0;i<n;i++)
//         {
//             if(arr[i]==0)
//             {
//                 count++;
//             }
//         }
//         return count;
//     }
// };


// Time complexity --> O(logn)
class Solution{   
public:
    // if 0 is present in arr[] then return the index of first occurence of 0 in arr[low....high], otherwise return -1
    int firstZero(int arr[],int low, int high)
    {
        if(low<=high)
        {
            // check if mid element is first 0
            int mid=low+(high-low)/2; // to prevent integer overflow
            if((mid==0 || arr[mid-1]==1) && arr[mid]==0)
            {
                return mid;
            }
            // if mid element is not 0
            if(arr[mid]==1)
            {
                return firstZero(arr,mid+1,high);
            }
            // if mid element is 0, but not first 0
            else
            {
                return firstZero(arr,low,mid-1);
            }
        }
        return -1;
    }
    int countZeroes(int arr[], int n) {
        // code here
        // find index of first zero in given array
        int first=firstZero(arr,0,n-1);
        
        // if 0 is not present at all, return 0
        if(first==-1)
        {
            return 0;
        }
        
        return (n-first);
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
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countZeroes(arr, n);
        cout << ans << "\n";
    }
    return 0;
}


// } Driver Code Ends


// Question link -- https://practice.geeksforgeeks.org/problems/count-the-zeros2550/1?page=2&difficulty[]=0&category[]=Arrays&sortBy=submissions