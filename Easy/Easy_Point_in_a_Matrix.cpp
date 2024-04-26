/*
Exit Point in a Matrix


Given a matrix of size n x m with 0’s and 1’s, you enter the matrix at cell (0,0) in left to right direction. Whenever you encounter a 0 you retain it in the same direction, else if you encounter a 1 you have to change the direction to the right of the current direction and change that 1 value to 0, you have to find out from which index you will leave the matrix at the end.

Example 1:

Input: 
n = 3, m = 3
matrix = {{0, 1, 0},
          {0, 1, 1}, 
          {0, 0, 0}}
Output: 
{1, 0}
Explanation: 
Enter the matrix at (0, 0) 
-> then move towards (0, 1) ->  1 is encountered 
-> turn right towards (1, 1)  -> again 1 is encountered 
-> turn right again towards (1, 0) 
-> now, the boundary of matrix will be crossed ->hence, exit point reached at 1, 0..



Example 2:

Input: 
n = 1, m = 2
matrix = {{0, 0}}
Output: 
{0, 1}
Explanation: 
Enter the matrix at cell (0, 0).
Since the cell contains a 0, we continue moving in the same direction.
We reach cell (0, 1), which also contains a 0. So, we continue moving in the same direction, we exit the matrix from cell (0, 1).


Your Task:
- You don't need to read or print anything. Your task is to complete the function FindExitPoint() which takes the matrix as an input parameter and returns a list containing the exit point.

Expected Time Complexity: O(n * m) where n = number of rows and m = number of columns.
Expected Space Complexity: O(1)

Constraints:
- 1 <= n, m <= 100
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Optimized Approach
// Time complexity -> O(n*m) and Space -> O(1)
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        int i=0,j=0;
        int dir=0;
        // For Dir
        // 0 -> left to right
        // 1 -> top to bottom
        // 2 -> right to left
        // 3 -> bottom to top
        
        while(i>=0 && i<n && j>=0 && j<m){
            if(matrix[i][j]==1){
                dir=(dir+1)%4;
                matrix[i][j]=0;
            }
            
            if(dir==0){
                j++;
            }
            else if(dir==1){
                i++;
            }
            else if(dir==2){
                j--;
            }
            else if(dir==3){
                i--;
            }
        }
        if(i<0){
            i++;
        }
        if(j<0){
            j++;
        }
        
        if(i==n){
            i--;
        }
        if(j==m){
            j--;
        }
        
        return {i,j};
        
    }
};


// OR
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        
      vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}}; //4 directions
      int i=0,j=0,direction_ptr=0;
       
      vector<int>res;
       
      while(i>=0 and i<n and  j>=0 and j<m){  //i and j within matrix bounds
          if(matrix[i][j]==1){
              direction_ptr=(direction_ptr+1)%4; 
              matrix[i][j]=0;
          }
          res={i,j}; //keep last valid i and j
          i=i+directions[direction_ptr][0];
          j=j+directions[direction_ptr][1];
      }
       
      return res;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1