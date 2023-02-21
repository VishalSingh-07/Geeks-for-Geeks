//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++

// Brute Force Approach
// Time complexity -> O(n^3) and Space --> O(1)

// class Solution{
// public:

// 	// Function to find maximum product subarray
// 	long long maxProduct(vector<int> arr, int n) {
// 	    // code here
// 	    long long max_product=INT_MIN;
// 	    for(int i=0;i<n;i++)
// 	    {
// 	        for(int j=i;j<n;j++)
// 	        {
// 	            long long product=1;
// 	            for(int k=i;k<=j;k++)
// 	            {
// 	                product*=arr[k];
// 	            }
// 	            if(product>max_product)
// 	            {
// 	                max_product=product;
// 	            }
// 	        }
// 	    }
// 	    return max_product;
// 	}
// };

// Above code give time limit exceeded due to high complexity O(n^3)

// Better Approach
// Time complexity --> O(n^2) and Space --> O(1)
// class Solution{
// public:

// 	// Function to find maximum product subarray
// 	long long maxProduct(vector<int> arr, int n) {
// 	    // code here
// 	    long long max_product=INT_MIN;
// 	    for(int i=0;i<n;i++)
// 	    {
// 	        long long product=1;
// 	        for(int j=i;j<n;j++)
// 	        {
// 	            product*=arr[j];
	           
// 	            if(product>max_product)
// 	            {
// 	                max_product=product;
// 	            }
// 	        }
// 	    }
// 	    return max_product;
// 	}
// };

// Above code give time limit exceeded due to high complexity O(n^2)

// Two Traversal Approach
//Time complexity --> O(n) and Space --> O(1)
// class Solution{
// public:

// 	// Function to find maximum product subarray
// 	long long maxProduct(vector<int> arr, int n) {
// 	    // code here
// 	    long long maxi=INT_MIN;
// 	    long long product=1;
// 	    for(int i=0;i<n;i++)
// 	    {
// 	        product*=arr[i];
// 	        maxi=max(maxi,product);
// 	        if(product==0)
// 	        {
// 	            product=1;
// 	        }
// 	    }
// 	    product=1;
// 	    for(int i=n-1;i>=0;i--)
// 	    {
// 	        product*=arr[i];
// 	        maxi=max(maxi,product);
// 	        if(product==0)
// 	        {
// 	            product=1;
// 	        }
// 	    }
// 	    return maxi;
// 	}
// };

// Optimized Approach [Kadane's Algorithm]
//Time complexity --> O(n) and Space --> O(1)
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long ans=arr[0];
	    long long max_product=ans;
	    long long min_product=ans;
	    
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i]<0)
	        {
	            swap(max_product,min_product);
	        }
	        max_product=max((long long)arr[i],max_product*arr[i]);
	        min_product=min((long long)arr[i],min_product*arr[i]);
	        
	        ans=max(ans,max_product);
	    }
	    return ans;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

/*
1. Question link -- https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

2. My Solution link -- https://leetcode.com/problems/maximum-product-subarray/solutions/3209734/4-approaches-easy-c-solution-brute-force-better-two-traversal-optimized-kadane-s/

3. Video link --
      
      i) https://youtu.be/GbJh0MjUa5U
      
      ii) https://youtu.be/tHNsZHXnYd4
*/