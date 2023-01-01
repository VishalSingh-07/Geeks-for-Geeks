//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Time complexity --> O(n^3) and space --> O(1)
// class Solution{
//     public:
//     //Function to find if there exists a triplet in the 
//     //array A[] which sums up to X.
//     bool find3Numbers(int A[], int n, int X)
//     {
//         //Your Code Here
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 for(int k=j+1;k<n;k++)
//                 {
//                     if(A[i]+A[j]+A[k]==X)
//                     {
//                         return 1;
//                     }
//                 }
//             }
//         }
//         return 0;
//     }

// };

// Above code is not submittable due to high complexity and time limit exceeded

// Time complexity --> O(nlogn) + O(n^2) ==> O(n^2) and space --> O(1)
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A,A+n);
        for(int i=0;i<n;i++)
        {
            int j=i+1,k=n-1;
            while(j<k)
            {
                int sum=A[i]+A[j]+A[k];
                if(sum==X)
                {
                    return true;
                }
                else if(sum<X)
                {
                    j++;
                }
                else if(sum>X)
                {
                    k--;
                }
            }
        }
        return false;
    }

};


//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends


// Question link --> https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1?page=1&status[]=bookmarked&sortBy=submissions