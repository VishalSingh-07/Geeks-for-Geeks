/*

Longest Sub Array with sum k Positive + Negative Integers

Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

 

Example 1:
 

Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.


Example 2:

Input : 
A[] = {-1, 2, 3}
K = 6
Output : 0
Explanation: 
There is no such sub-array with sum 6.
Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function lenOfLongSubarr() that takes an array (A), sizeOfArray (n),  sum (K)and returns the required length of the longest Sub-Array. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

 

Constraints:
1<=N<=105
-105<=A[i], K<=105
 
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(n^3) and Space -> O(1)
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int K) 
    { 
        // Complete the function
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int sum=0;
                for(int k=i;k<=j;k++)
                {
                    sum+=arr[k];
                }
                if(sum==K)
                {
                    maxLen=max(maxLen,j-i+1);
                }
            }
        }
        return maxLen;
        
    } 

};

// Above code give Time Limit Exceeded due to High Complexity O(n^3)


// Better Approach
// Time complexity -> O(n^2) and Space -> O(1)
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int K) 
    { 
        // Complete the function
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=arr[j];
                if(sum==K)
                {
                    maxLen=max(maxLen,j-i+1);
                }
            }
        }
        return maxLen;
        
    } 

};

// Above code give Time Limit Exceeded due to High Complexity O(n^2)


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        unordered_map<int,int> mpp;
        int maxLen=0;
        int prefixsum=0;
        for(int i=0;i<n;i++)
        {
            prefixsum+=arr[i];
            if(prefixsum==k)
            {
                maxLen=max(maxLen,i+1);
            }
            int remainingsum=prefixsum-k;
            if(mpp.find(remainingsum)!=mpp.end())
            {
                int len=i-mpp[remainingsum];
                maxLen=max(maxLen,len);
            }
            if(mpp.find(prefixsum)==mpp.end())
            {
                mpp[prefixsum]=i;
            }
        }
        return maxLen;
        
    } 

};




//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends

/*
1. Question link -- https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

2. Video Link -- https://youtu.be/frf7qxiN2qU
*/