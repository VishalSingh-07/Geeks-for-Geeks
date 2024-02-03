/*
Largest Subarray with 0 sum 


Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
-1000 <= A[i] <= 1000, for each valid i
*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

// Brute Force Approach
// Time complexity -> O(n^3) and Space -> O(1)
class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                long long sum=0;
                for(int k=i;k<=j;k++)
                {
                    sum+=a[k];
                }
                if(sum==0)
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
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            long long sum=0;
            for(int j=i;j<n;j++)
            {
                
                sum+=a[j];
                if(sum==0)
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
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        unordered_map<long long,int> mpp;
        int prefixsum=0;
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            prefixsum+=a[i];
            if(prefixsum==0)
            {
                maxLen=max(maxLen,i+1);
            }
            if(mpp.find(prefixsum)!=mpp.end())
            {
                maxLen=max(maxLen,i-mpp[prefixsum]);
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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends

/*
1. Question link -- https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

2. Video Link -- https://youtu.be/frf7qxiN2qU
*/