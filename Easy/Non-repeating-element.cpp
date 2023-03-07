//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

// Approach 1: Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
// class Solution{
//     public:
//     int firstNonRepeating(int arr[], int n) 
//     { 
//         // Complete the function
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
//             if(count==1)
//             {
//                 return arr[i];
//             }
//         }
//         return 0;
        
//     } 
  
// };

// Above code give time limit exceeded due to high complexity O(n^2)


// Approach 2: Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution{
    public:
    int firstNonRepeating(int arr[], int n) 
    { 
        // Complete the function
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[arr[i]]==1)
            {
                return arr[i];
            }
        }
        return 0;
        
    } 
  
};


//{ Driver Code Starts.

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.firstNonRepeating(arr,n)<<endl;
    }
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/non-repeating-element3958/1