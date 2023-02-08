//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

// Brute Force Approach
// Time complexity --> O(n*m) and space --> O(1)
// where n = number of rows and m = number of columns
// class Solution
// {
//     public:
//     //Function to search a given number in row-column sorted matrix.
//     bool search(vector<vector<int> > matrix, int n, int m, int x) 
//     {
//         // code here 
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(matrix[i][j]==x)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// Binary Search Approach [Applying binary search on each row]
// Time complexity --> O(n*logm) and space --> O(1)
// where n = number of rows and m = number of columns
// class Solution
// {
//     public:
//     //Function to search a given number in row-column sorted matrix.
//     bool search(vector<vector<int> > matrix, int n, int m, int x) 
//     {
//         // code here 
//         for(int i=0;i<n;i++)
//         {
//             int low=0,high=m-1;
//             while(low<=high)
//             {
//                 int mid=low+(high-low)/2;
//                 if(matrix[i][mid]==x)
//                 {
//                     return true;
//                 }
//                 else if(matrix[i][mid]>x)
//                 {
//                     high=mid-1;
//                 }
//                 else if(matrix[i][mid]<x)
//                 {
//                     low=mid+1;
//                 }
                
//             }
//         }
//         return false;
//     }
// };


// Optimized Approach
// Time complexity --> O(n+m) and space --> O(1)
// where n = number of rows and m = number of columns
class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        // code here 
        int row=0;
        int col=m-1;
        while(row<n && col>=0)
        {
            if(matrix[row][col]==x)
            {
                return true;
            }
            else if(matrix[row][col]>x)
            {
                col--;
            }
            else if(matrix[row][col]<x)
            {
                row++;
            }
            
            
        }
        return false;
    }
};




// Leetcode :: [Search a 2D Matrix II] is same as GFG [Search in a row-column sorted matrix]


//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends


// Question link -- https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1


// Video Link -- https://youtu.be/ZYpYur0znng

// My Solution -- https://leetcode.com/problems/search-a-2d-matrix-ii/solutions/3127608/3-approach-to-solve-a-problem-easy-c-solution-brute-force-binary-search-optimized/