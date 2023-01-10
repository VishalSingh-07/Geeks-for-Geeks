//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

// Time complexity --> O(n) and space --> O(n)
class Solution{
public:	
	vector<float> streamAvg(int arr[], int n) {
	    // code here
	    vector<float> ans;
	    float sum=0, count=1;
	    for(int i=0;i<n;i++)
	    {
	        sum=sum+arr[i];
	        ans.push_back(sum/count);
	        count++;
	    }
	    return ans;
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
        auto ans = ob.streamAvg(arr, n);
        cout << fixed<< setprecision(2);
        for (auto x : ans) {
            cout <<x<<" ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends

// Question --> https://practice.geeksforgeeks.org/problems/average4856/1