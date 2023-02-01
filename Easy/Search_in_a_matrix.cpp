//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// Brute Force Approach
// Time complexity --> O(N*M) and Space --> O(1)
// class Solution{
// public:	
// 	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
// 	{
// 	    // your code here
// 	    for(int i=0;i<N;i++)
// 	    {
// 	        for(int j=0;j<M;j++)
// 	        {
// 	            if(mat[i][j]==X)
// 	            {
// 	                return 1;
// 	            }
// 	        }
// 	    }
// 	    return 0;
// 	}
// };


// Applying binary search on each row
// Time complexity --> O(N*logM) and Space --> O(1)
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	    for(int i=0;i<N;i++)
	    {
	        int low=0,high=M-1;
	        while(low<=high)
	        {
	            int mid=low+(high-low)/2;
	            if(X>mat[i][mid])
	            {
	                low=mid+1;
	            }
	            else if(X<mat[i][mid])
	            {
	                high=mid-1;
	            }
	            else if(X==mat[i][mid])
	            {
	                return 1;
	            }
	        }
	        
	        
	    }
	    
	    return 0;
	}
};

// Optimized Approach
// Time complexity --> O(N + M) and Space --> O(1)
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	    int i=0,j=M-1;
	    while(i<N && j>=0)
	    {
	        if(X>mat[i][j])
	        {
	            i++;
	        }
	        else if(X<mat[i][j])
	        {
	            j--;
	        }
	        else if(X==mat[i][j])
	        {
	            return 1;
	        }
	    }
	    return 0;
	}
};
//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

// Video Link -- https://youtu.be/ZYpYur0znng

// My Detail Solution link -- https://leetcode.com/problems/search-a-2d-matrix/solutions/3122363/4-approach-to-solve-a-problem-easy-c-solution-brute-force-to-optimized-approach/
