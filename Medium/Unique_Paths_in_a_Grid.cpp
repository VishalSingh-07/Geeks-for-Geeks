//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


// Brute Force Approach [Recursion]
// Time complexity -> O(2^(m+n)) and Space -> O(m+n)
class Solution {
  private:
        int countUniquePaths(int i, int j, int m, int n,vector<vector<int>> &grid)
        {
            const int mod=1000000007;
            if(i==(n-1) && j==(m-1))
            {
                  return 1;
            }
            if(i>=n || j>=m || grid[i][j]==0)
            {
                  return 0;
            }
            return (countUniquePaths(i+1,j,m,n,grid)%mod+countUniquePaths(i,j+1,m,n,grid)%mod)%mod;
      }    
  public:
        int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        if(grid[0][0]==0 || grid[n-1][m-1]==0)
        {
            return 0;
        }
        return countUniquePaths(0,0,m,n,grid);
    }
};

// Above Code give timit limit exceeded due to exponential time complexity


// Optimized Approach [Dynamic Programming]
// Time complexity -> O(m*n) and Space -> O(m*n)
class Solution {
  private:
        int countUniquePaths(int i, int j, int m, int n,vector<vector<int>> &grid,vector<vector<int>> &dp)
        {
            const int mod=1000000007;
            if(i==(n-1) && j==(m-1))
            {
                  return 1;
            }
            if(i>=n || j>=m || grid[i][j]==0)
            {
                  return 0;
            }
            if(dp[i][j]!=-1)
            {
                  return dp[i][j]%mod;
            }
            return dp[i][j]=(countUniquePaths(i+1,j,m,n,grid,dp)%mod+countUniquePaths(i,j+1,m,n,grid,dp)%mod)%mod;
      }    
  public:
        int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        vector<vector<int>> dp(n,vector<int>(m,-1));
        if(grid[0][0]==0 || grid[n-1][m-1]==0)
        {
            return 0;
        }
        return countUniquePaths(0,0,m,n,grid,dp);
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*

1. Question link -- https://practice.geeksforgeeks.org/problems/96161dfced02d544fc70c71d09b7a616fe726085/1

2. Solution link -- https://leetcode.com/problems/unique-paths/solutions/3829439/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/

3. Video link -- https://youtu.be/t_f0nwwdg5o

*/