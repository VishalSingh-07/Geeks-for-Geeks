/*
Row with max 1s

Given a boolean 2D array, consisting of only 1's and 0's, where each row is sorted. Return the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.

Examples:

Input: arr[][] = [[0, 1, 1, 1],
               [0, 0, 1, 1],
               [1, 1, 1, 1],
               [0, 0, 0, 0]]
Output: 2
Explanation: Row 2 contains 4 1's (0-based indexing).




Input: arr[][] = [[0, 0], 
               [1, 1]]
Output: 1
Explanation: Row 1 contains 2 1's (0-based indexing).



Expected Time Complexity: O(n+m)
Expected Auxiliary Space: O(1)

Constraints:
- 1 ≤ number of rows, number of columns ≤ 10^3
- 0 ≤ arr[i][j] ≤ 1 
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


// Brute Force Approach
// Time complexity -> O(n*m) and Space -> O(1)
// where n: number of rows and m: number of columns
/*Hint : 
A simple solution would be to count a total number of 1's in each row 
of the matrix and return the index of the row having maximum 1's.
*/
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int rowIndex=-1;
        int maxOnes=0;
        for(int i=0;i<arr.size();i++){
            int ones=0;
            for(int j=0;j<arr[i].size();j++){
                if(arr[i][j]==1){
                    ones++;
                }
            }
            if(ones>maxOnes){
                maxOnes=ones;
                rowIndex=i;
            }
        }
        return rowIndex;
    }
};


// Optimized Approach
// Time complexity -> O(n+m) and Space -> O(1)
// where n: number of rows and m: number of columns
/*
Hint: 
To solve in O(n + m) start from the top right corner of the matrix 
and keep track of the index of the row which has maximum 1s. 
Go left if you encounter 1, Go down if you encounter 0, Stop when you reach 
the last row or first column. 
*/
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        
        int row=0;
        int col=m-1;
        
        int index=-1;
        while(row<n && col>=0){
            if(arr[row][col]==1){
                index=row;
                col--;
            }
            else{
                row++;
            }
        }
        return index;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends


// Question link -- https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1