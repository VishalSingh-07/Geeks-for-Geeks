//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Brute Force Approach
// Time complexity --> O(n^2) and Space --> O(1)
// class Solution
// {
//   public:
//     int countPairs(int arr1[], int arr2[],  int m, int n, int x) 
//     { 
//         //code here.
//         int count=0;
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(arr1[i]+arr2[j]==x)
//                 {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     } 
// };

// Above code give time limit exceeded due to high complexity O(n^2)

// Optimized Approach
// Time complexity --> O(m+n) and Space --> O(1)
class Solution
{
  public:
    int countPairs(int arr1[], int arr2[],  int m, int n, int x) 
    { 
        //code here.
        int count=0;
        int i=0;
        int j=n-1;
        while(i<m && j>=0)
        {
            if(arr1[i]+arr2[j]==x)
            {
                count++;
                i++;
                j++;
            }
            else if(arr1[i]+arr2[j]<x)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return count;
        
    } 
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    int arr1[m],arr2[n];
	    int x ;
	    for(int i=0;i<m;i++)
	        cin>>arr1[i];
	    for(int j=0;j<n;j++)
	        cin>>arr2[j];
	    cin>>x;
	    Solution ob;
	    cout <<ob.countPairs(arr1, arr2, m, n, x)<<endl;
	}
	return 0;	 
}


// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/count-pair-sum5956/1