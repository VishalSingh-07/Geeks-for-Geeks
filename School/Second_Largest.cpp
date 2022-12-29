//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int max=-1, second=-1;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>max || second<arr[i])
	        {
	            if(arr[i]>max)
	            {
	                second=max;
	                max=arr[i];
	            }
	            else if(arr[i]<max)
	            {
	                second=arr[i];
	            }
	        }
	    }
	    return second;
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