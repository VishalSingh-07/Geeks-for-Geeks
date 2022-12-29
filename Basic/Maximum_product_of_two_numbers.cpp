//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:

	int maxProduct(int arr[], int n) {
	    // code here
	   // vector<int> v;
	   // for(int i=0;i<n;i++)
	   // {
	   //     v.push_back(arr[i]*arr[i+1]);
	   // }
	   // return *max(v.begin(),v.end());
	   
	   sort(arr,arr+n);
	   int ans=arr[n-1]*arr[n-2]; // last two digit because they are bigger one
	   
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
        int arr[n];
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

// Question Link -- https://practice.geeksforgeeks.org/problems/maximum-product-of-two-numbers2730/1?page=1&status[]=bookmarked&sortBy=submissions
