//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

// Brute Force Approach
// Time complexity --> O(n^2) and Space -> O(n^2)

class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        // code here 
        vector<vector<int>> rotate(n, vector <int> (n, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                rotate[i][j]=matrix[j][n-i-1];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=rotate[i][j];
            }
        }
    } 
};


// Optimized Approach
// Time complexity --> O(n^2) and Space -> O(1)
class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        // code here 
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
};





//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*
1. Question link -- https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1

2. My Solution link --

      a) GFG: https://discuss.geeksforgeeks.org/comment/5077066bd04c4aa22b7a14c7b35d49e1

      b) Leetcode: https://leetcode.com/problems/rotate-image/solutions/3236044/2-approach-easy-c-solution-brute-force-optimized-approach-dry-run-of-a-program/

3. Video Link -- https://youtu.be/Y72QeX0Efxw

*/