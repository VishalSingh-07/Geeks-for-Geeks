//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
	    //code
	    // First Approach -- Time Complexity --> O(n^2)
	   // int count=0;
	   // for(int i=0;i<N;i=i+2)
	   // {
	   //     for(int j=0;j<N;j++)
	   //     {
	   //         if(A[i]==A[j])
	   //         {
	   //             count++;
	   //         }
	            
	   //     }
	   //     if(count%2!=0)
	   //     {
	   //         return A[i];
	   //     }
	       
	   // }
	    
	    // Second Approach -- Time complexity -- O(n)
	    /*
            x^0=x
            x^y=y^x
            x^(y^z)=(x^y)^z
            x^x=0
        */
        int res = 0;
        for (int i = 0; i <N;i++)
        {
              res = res ^ A[i];
        }
        return res;
        
	   
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends


// Question Link -- https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1?page=1&difficulty[]=1&status[]=solved&sortBy=submissions