//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
// Time complexity --> O(n) and space --> O(1)
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int j=0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]!=0)
	        {
	            arr[j]=arr[i];
	            j++;
	        }
	    }
	    for(;j<n;j++)
	    {
	        arr[j]=0;
	    }
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
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1?page=1&status[]=bookmarked&sortBy=submissions