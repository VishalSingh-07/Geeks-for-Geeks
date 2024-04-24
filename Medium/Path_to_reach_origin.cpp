/*
Paths to reach origin

You are standing on a point (x, y) and you want to go to the origin (0, 0) by taking steps either left or down i.e. from each point you are allowed to move either in (x-1, y) or (x, y-1). Find the number of paths from point to origin.

Example 1:

Input:
x = 3, y = 0 
Output: 
1
Explanation: Path used was -  (3,0)  --> ( 2,0) --> (1,0) --> (0,0).We can see that there is no other path than this, so we return 1.



Example 2:

Input:
x = 3, y = 6
Output: 
84 
Explanation:
There are total 84 possible paths.

Your Task:
- Since this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function ways() that takes integer x and y as parameters and returns the total number of paths from point(x,y) to the origin(0,0) % 1000000007.

Expected Time Complexity: O(x*y).
Expected Auxiliary Space: O(x*y).

Constraints:
0 ≤ x, y ≤ 500



*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// Brute Force Approach
// Time complexity -> O(2^n) and Space -> O(n)
// where n= x + y
class Solution
{
    int mod=1e9+7;
public:
    int ways(int x, int y)
    {
        if(x==0 && y==0){
            return 1;
        }
        int left=y>0?ways(x,y-1)%mod:0;
        int up=x>0?ways(x-1,y)%mod:0;
        
        return (left+up)%mod;
    }
};

// Above code give time limit Exceeded due to high complexity O(2^n)


// Optimized Approach [Memoization]
// Time complexity -> O(x*y) and Space -> O(x*y)
class Solution
{
    int mod=1e9+7;
    int solve(int x, int y, vector<vector<int>> &dp){
        if(x==0 && y==0){
            return 1;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        int left=y>0?solve(x,y-1,dp)%mod:0;
        int up=x>0?solve(x-1,y,dp)%mod:0;
        
        return dp[x][y] = (left+up)%mod;
    }
public:
    int ways(int x, int y)
    {
        vector<vector<int>> dp(x+1,vector<int> (y+1,-1));
        return solve(x,y,dp);
    }
};





//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends

/*
1. Question link --  https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1

2. Video Link -- https://youtu.be/qKwZiEg0NrY?feature=shared
*/