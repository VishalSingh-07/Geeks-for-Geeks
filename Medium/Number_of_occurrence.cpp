//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

// Brute Force Approach
// Time complexity -> O(2n) and Space -> O(n)

// class Solution{
// public:	
// 	/* if x is present in arr[] then returns the count
// 		of occurrences of x, otherwise returns 0. */
// 	int count(int arr[], int n, int x) {
// 	    // code here
// 	   unordered_map<int,int> mpp;
// 	   for(int i=0;i<n;i++)
// 	   {
// 	       mpp[arr[i]]++;
// 	   }
// 	   for(auto it: mpp)
// 	   {
// 	       if(it.first==x)
// 	       {
// 	           return it.second;
// 	       }
// 	   }
// 	   return 0;
// 	}
// };

// Better Approach
// Time complexity -> O(n) and Space -> O(1)

// class Solution{
// public:	
// 	/* if x is present in arr[] then returns the count
// 		of occurrences of x, otherwise returns 0. */
// 	int count(int arr[], int n, int x) {
// 	    // code here
// 	    int occurrence=0;
// 	    for(int i=0;i<n;i++)
// 	    {
// 	        if(arr[i]==x)
// 	        {
// 	            occurrence++;
// 	        }
// 	    }
// 	    return occurrence;
// 	}
// };


// Optimized Approach
// Time complexity -> O(logn) and Space -> O(1)

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    auto i=lower_bound(arr,arr+n,x);
	    auto j=upper_bound(arr,arr+n,x);
	    
	    return j-i;
	}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1