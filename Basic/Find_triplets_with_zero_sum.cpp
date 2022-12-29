//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    
    
    // Time complexity --- O(n^3)
    
    // bool findTriplets(int arr[], int n)
    // { 
    //     //Your code here
    //     for(int i=0;i<n-2;i++)
    //     {
    //         for(int j=i+1;j<n-1;j++)
    //         {
    //             for(int k=j+1;k<n;k++)
    //             {
    //                 if(arr[i]+arr[j]+arr[k]==0)
    //                 {
    //                     return true;
    //                 }
    //             }
    //         }
    //     }
        
    //     return false;
    // }
    
    
    // Time complexity --> O(n^2) + O(nlogn) ~~ O(n^2)
    // Two pointer Approach
    
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        sort(arr,arr+n); 
        
        for(int i=0;i<n;i++)
        {
            int j=i+1,k=n-1;
            while(j<k)
            {
                int sum=arr[i]+arr[j]+arr[k];
                if(sum==0)
                {
                    return true; // because we found the triplet with zero sum
                }
                else if(sum<0)
                {
                    j++; 
                    // because to increase the sum of triplet which is negative to make closer to zero
                    // we move from right to left in sorted array for increasing  the sum
                }
                else if(sum>0)
                {
                    k--; 
                    // because to decrease the sum of triplet which is positive to make closer to zero
                    // we move from right to left in sorted array for decreasing the sum
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends


// Question Link -- https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1?page=1&status[]=bookmarked&sortBy=submissions