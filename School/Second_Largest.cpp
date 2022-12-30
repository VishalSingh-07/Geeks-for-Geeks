//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++

// Approach 1
// class Solution{
// public:	
// 	// Function returns the second
// 	// largest elements
// 	int print2largest(int arr[], int n) {
// 	    // code here
// 	    int max=-1, second=-1;
// 	    for(int i=0;i<n;i++)
// 	    {
// 	        if(arr[i]>max || second<arr[i])
// 	        {
// 	            if(arr[i]>max)
// 	            {
// 	                second=max;
// 	                max=arr[i];
// 	            }
// 	            else if(arr[i]<max)
// 	            {
// 	                second=arr[i];
// 	            }
// 	        }
// 	    }
// 	    return second;
// 	}
// };

// Approach 2
// class Solution{
// public:	
// 	// Function returns the second
// 	// largest elements
// 	int print2largest(int arr[], int n) {
// 	    // code here
// 	    int max=INT_MIN;
// 	    int second_max=INT_MIN;
	    
// 	    for(int i=0;i<n;i++)
// 	    {
// 	        if(arr[i]>max)
// 	        {
// 	            max=arr[i];
// 	        }
// 	    }
	    
// 	    for(int i=0;i<n;i++)
// 	    {
// 	        if(arr[i]<max && arr[i]>second_max)
// 	        {
// 	            second_max=arr[i];
// 	        }
// 	    }
	    
// 	    if(max==INT_MIN || second_max==INT_MIN)
// 	    {
// 	        return -1;
// 	    }
// 	    else
// 	    {
// 	        return second_max;
// 	    }
// 	}
// };


// Approach 3

class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    sort(arr,arr+n);
	    if(n==1)
	    {
	        return -1;
	    }
	    
	    for(int i=n-2;i>=0;i--)
	    {
	        
	        if(arr[i]!=arr[n-1]) // it will check if the element is same as the largest element or not
	        {
	            return arr[i];
	        }
	        
	    }
	    
	    return -1;
	   
	}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends

// Question Link: -- https://practice.geeksforgeeks.org/problems/second-largest3735/1?page=1&difficulty[]=-2&status[]=solved&category[]=Arrays&sortBy=submissions