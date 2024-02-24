/*
Maximum Sum Problem


A number n can be broken into three parts n/2, n/3, and n/4 (consider only the integer part). Each number obtained in this process can be divided further recursively. Find the maximum sum that can be obtained by summing up the divided parts together.
Note: It is possible that we don't divide the number at all.

Example 1:

Input:
n = 12
Output: 
13
Explanation: 
Break n = 12 in three parts {12/2, 12/3, 12/4} = {6, 4, 3}, now current sum is = (6 + 4 + 3) = 13. Further breaking 6, 4 and 3 into parts will produce sum less than or equal to 6, 4 and 3 respectively.


Example 2:

Input:
n = 24
Output: 
27
Explanation: 
Break n = 24 in three parts {24/2, 24/3, 24/4} = {12, 8, 6}, now current sum is = (12 + 8 + 6) = 26 . But recursively breaking 12 would produce value 13. So our maximum sum is 13 + 8 + 6 = 27.


Your Task:
You don't need to read input or print anything. Your task is to complete the function maxSum() which accepts an integer n and returns the maximum sum.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
0 <= n <= 106
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(2^n) and Space -> O(n)
class Solution
{
    public:
        int maxSum(int n)
        {
            //code here.
            if(n<12)
            {
                return n;
            }
            return maxSum(n/2)+maxSum(n/3)+maxSum(n/4);
        }
};


// Optimized Approach [Using Dynamic Programming]
// Time complexity -> O(n) and Space -> O(n)
class Solution
{
    public:
        int maxSum(int n)
        {
            //code here.
            vector<int> dp(n+1,INT_MIN);
            dp[0]=0;
            dp[1]=1;
            dp[2]=2;
            dp[3]=3;
            dp[4]=4;
            
            for(int i=5;i<=n;i++)
            {
                int sum=dp[i/2]+dp[i/3]+dp[i/4];
                dp[i]=max(i,sum);
            }
            return dp[n];
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
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}

// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1