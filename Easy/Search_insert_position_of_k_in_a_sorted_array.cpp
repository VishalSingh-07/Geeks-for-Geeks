//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

// Brute Force Approach
// Time complexity --> O(n) and Space --> O(1)
// class Solution{
//     public:
//     int searchInsertK(vector<int>arr, int n, int k)
//     {
//         // code here
//         for(int i=0;i<n;i++)
//         {
//             if(arr[i]==k)
//             {
//                 return i;
//             }
//             else if(arr[i]>k)
//             {
//                 return i;
//             }
//         }
        
//         return n;
        
//     }
// };

// Optimized Approach
// Time complexity --> O(logn) and Space --> O(1)
class Solution{
    public:
    int searchInsertK(vector<int>arr, int n, int k)
    {
        // code here
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==k)
            {
                return mid;
            }
            else if(arr[mid]>k)
            {
                high=mid-1;
            }
            else if(arr[mid]<k)
            {
                low=mid+1;
            }
        }
        return low;
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends


// Question link -- https://practice.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1

// Video link -- https://youtu.be/0A40XJH_VvE