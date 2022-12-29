//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        // int dp[sum+1][N+1];
        // for(int i=0;i<=N;i++)
        // {
        //     dp[0][i]=1;
        // }
        // for(int i=1;i<=sum;i++)
        // {
        //     dp[i][0]=0;
        // }
        // for(int i=1;i<=sum;i++)
        // {
        //     for(int j=1;j<=N;j++)
        //     {
        //         dp[i][j]=dp[i][j-1];
        //         if(coins[j-1]<=i)
        //         {
        //             dp[i][j] += dp[i-coins[j-1]][j];
        //         }
        //     }
        // }
        // return dp[sum][N];
        
        long long int dp[N+1][sum+1];
      
      for(int i=0; i<=N; i++){
          for(int j=0; j<=sum; j++){
              if(i==0){
                  dp[i][j] = 0;
              }
              if(j==0){
                  dp[i][j] = 1;
              }
          }
      }
      
      for(int i=1; i<=N; i++){
          for(int j=1; j<=sum; j++){
              if(coins[i-1] <= j){
                  dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
              }
              else{
                  dp[i][j] = dp[i-1][j];
              }
          }
      }
      return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends

// Question Link --- https://practice.geeksforgeeks.org/problems/coin-change2448/1?page=1&difficulty[]=1&status[]=solved&category[]=Arrays&sortBy=submissions