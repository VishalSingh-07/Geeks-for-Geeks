//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

// Approach 1 [Using Two Vector]
// Time complexity --> O(n) and Space --> O(n)
// class Solution{
// public:

// 	void rearrange(int arr[], int n) {
// 	    // code here
// 	    vector<int> positive,negative;
// 	    for(int i=0;i<n;i++)
// 	    {
// 	        if(arr[i]>=0)
// 	        {
// 	            positive.push_back(arr[i]);
// 	        }
// 	        else
// 	        {
// 	            negative.push_back(arr[i]);
// 	        }
	        
// 	    }
// 	    if(positive.size()==0 || negative.size()==0)
// 	    {
// 	        return;
// 	    }
// 	    int i=0,j=0,k=0;
// 	    while(i<positive.size() && j<negative.size())
// 	    {
// 	        arr[k++]=positive[i++];
// 	        arr[k++]=negative[j++];
// 	    }
// 	    while(i<positive.size())
// 	    {
// 	        arr[k++]=positive[i++];
// 	    }
// 	    while(j<negative.size())
// 	    {
// 	        arr[k++]=negative[j++];
// 	    }
	    
// 	}
// };



// Approach 2 [Using Queue]
// Time complexity --> O(n) and Space --> O(n)
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    queue <int> positive;
	    queue <int> negative;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0)
	        {
	            positive.push(arr[i]);
	        }
	        else
	        {
	            negative.push(arr[i]);
	        }
	        
	    }
	    for(int i=0;i<n;)
	    {
	        if(!positive.empty())
	        {
	            arr[i++]=positive.front();
	            positive.pop();
	        }
	        if(!negative.empty())
	        {
	            arr[i++]=negative.front();
	            negative.pop();
	        }
	        
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
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends


// Question link --https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1