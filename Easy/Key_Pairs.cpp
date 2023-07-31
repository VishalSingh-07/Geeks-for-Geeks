//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    for(int i=0;i<n;i++)
	    {
	        for(int j=i+1;j<n;j++)
	        {
	            if(arr[i]+arr[j]==x)
	            {
	                return true;
	            }
	        }
	    }
	    return false;
	}
};

// Above code give time limit Exceeded due to high time complexity.

// Better Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    unordered_map<int,int> mpp;
	    for(int i=0;i<n;i++)
	    {
	        if(mpp.find(x-arr[i])!=mpp.end())
	        {
	            return true;
	        }
	        mpp[arr[i]]=i;
	    }
	    return false;
	}
};


// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(1)
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    sort(arr,arr+n);
	    int left=0;
	    int right=n-1;
	    while(left<right)
	    {
	        if(arr[left]+arr[right]==x)
	        {
	            return true;
	        }
	        else if(arr[left]+arr[right]<x)
	        {
	            left++;
	        }
	        else
	        {
	            right--;
	        }
	    }
	    return false;
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
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends


/*

1. Question link -- https://practice.geeksforgeeks.org/problems/key-pair5616/1

2. Video Link -- https://youtu.be/UXDSeD9mN-k

*/