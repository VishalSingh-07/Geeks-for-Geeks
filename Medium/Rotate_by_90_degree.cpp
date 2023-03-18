/*
Rotate by 90 degree

Given a square matrix[][] of size N x N. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.

Example 1:

Input:
N = 3
matrix[][] = [[1 2 3],
              [4 5 6],
              [7 8 9]]


Output:
3 6 9 
2 5 8 
1 4 7


Your Task:
You only need to implement the given function rotate(). Do not read input, instead use the arguments given in the function. 

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 50
1 <= matrix[][] <= 100



*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


// } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
 
// Brute Force Approach
// Time complexity -> O(n*n) and Space -> O(n*n)
// void rotate(vector<vector<int> >& matrix)
// {
//     // Your code goes here
//     int n=matrix.size();
//     vector<vector<int>> rotated(n, vector <int> (n, 0));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             rotated[i][j]=matrix[j][n-i-1];
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             matrix[i][j]=rotated[i][j];
//         }
//     }
// }

 // Optimized Approach
 // Time complexity -> O(n*n) and Space -> O(1)
void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int n=matrix.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        int start=0,end=n-1;
        while(start<end)
        {
            swap(matrix[start][i],matrix[end][i]);
            start++;
            end--;
        }
    }
    
}





//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}


// } Driver Code Ends

/*
1. Question link -- https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1

2. My Solution link --
      
      Leetcode: https://leetcode.com/problems/rotate-image/solutions/3236044/2-approach-easy-c-solution-brute-force-optimized-approach-dry-run-of-a-program/

3. Video Link -- https://youtu.be/Y72QeX0Efxw
*/