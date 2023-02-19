//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Brute Force Approach
// Time complexity --> O(n^3) and Space --> O(1)

// class Solution{
//     public:
//     // arr: input array
//     // n: size of array
//     //Function to find the sum of contiguous subarray with maximum sum.
//     long long maxSubarraySum(int arr[], int n){
        
//         // Your code here
//         long long max_sum=INT_MIN;
//         if(n==1)
//         {
//             return arr[0];
//         }
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i;j<n;j++)
//             {
//                 long long sum=0;
//                 for(int k=i;k<=j;k++)
//                 {
//                     sum+=arr[k];
//                 }
//                 if(sum>max_sum)
//                 {
//                     max_sum=sum;
//                 }
//             }
//         }
//         return max_sum;
//     }
// };

// Above code ❌ give Time limit exceeded due to high time complexity O(n^3) 


// Better Approach
// Time complexity --> O(n^2) and Space --> O(1)
// class Solution{
//     public:
//     // arr: input array
//     // n: size of array
//     //Function to find the sum of contiguous subarray with maximum sum.
//     long long maxSubarraySum(int arr[], int n){
        
//         // Your code here
//         long long max_sum=INT_MIN;
//         if(n==1)
//         {
//             return arr[0];
//         }
//         for(int i=0;i<n;i++)
//         {
//             long long sum=0;
//             for(int j=i;j<n;j++)
//             {
//                 sum+=arr[j];
//                 if(sum>max_sum)
//                 {
//                     max_sum=sum;
//                 }
//             }
//         }
//         return max_sum;
//     }
// };

// Above code ❌ give Time limit exceeded due to high time complexity O(n^2)

// Optimized Approach [Kadane's Algorithm]
// Time complexity --> O(n) and Space --> O(1)
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long sum=0;
        long long maxi=arr[0];
        
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            maxi=max(maxi,sum);
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends

/*
1. Question link -- https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

2. My Solution link -- https://leetcode.com/problems/maximum-subarray/solutions/3206363/3-approach-to-solve-a-problem-easy-c-solution-dry-run-of-optimized-solution/

3. Video link --

      i) https://youtu.be/w_KEocd__20

      ii) https://youtu.be/w4W6yya1PIc
*/