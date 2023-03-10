//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*
Hint 1: Scan the array and compute Maximum, second maximum, third maximum element, and minimum and second minimum element present in the array.

Hint 2: The answer will always be maximum of product of Maximum, second maximum and third maximum and product of Minimum, second minimum and Maximum element.
*/


// Brute Force Approach
// Time complexity -> O(nlogn) and Space -> O(1)
// class Solution {
//   public:
//     long long maxTripletProduct(long long arr[], int n)
//     {
//     	// Complete the function
//     	if(n<3)
//     	{
//     	    return -1;
//     	}
//     	sort(arr,arr+n);
//     	long long maxi=max(arr[n-3]*arr[n-2]*arr[n-1],arr[n-1]*arr[0]*arr[1]);
    	
//     	return maxi;
    	
//     }
// };


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    	long long first_max=INT_MIN;
    	long long second_max=first_max;
    	long long third_max=first_max;
    	
    	long long first_min=INT_MAX;
    	long long second_min=first_min;
    	
    	for(int i=0;i<n;i++)
    	{
    	    if(first_max<=arr[i])
    	    {
    	        third_max=second_max;
    	        second_max=first_max;
    	        first_max=arr[i];
    	    }
    	    else if(second_max<=arr[i])
    	    {
    	        third_max=second_max;
    	        second_max=arr[i];
    	    }
    	    else if(third_max<=arr[i])
    	    {
    	        third_max=arr[i];
    	    }
    	    
    	    if(first_min>=arr[i])
    	    {
    	        second_min=first_min;
    	        first_min=arr[i];
    	    }
    	    else if(second_min>=arr[i])
    	    {
    	        second_min=arr[i];
    	    }
    	}
    	long long maxi=max(first_max*second_max*third_max,first_max*first_min*second_min);
    	
    	return maxi;
    }
};







//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends



// Question link --https://practice.geeksforgeeks.org/problems/d54c71dc974b7db3a200eb63f34e3d1cba955d86/1

// Solution link -- https://leetcode.com/problems/maximum-product-of-three-numbers/solutions/3279567/2-approach-easy-c-solution-brute-force-sorting-and-optimized-approach/