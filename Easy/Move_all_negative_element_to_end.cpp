//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Approach 1
// Time complexity -> O(n) and Space --> O(n)
// class Solution{
//     public:
//     void segregateElements(int arr[],int n)
//     {
//         // Your code goes here
//         vector<int> ans;
//         // Storing positive element in a vector
//         for(int i=0;i<n;i++)
//         {
//             if(arr[i]>=0)
//             {
//                 ans.push_back(arr[i]);
//             }
//         }
//         // Storing negative element in a vector
//         for(int i=0;i<n;i++)
//         {
//             if(arr[i]<0)
//             {
//               ans.push_back(arr[i]);
//             }
//         }
//         // Copying vector element into array
//         for(int j=0;j<ans.size();j++)
//         {
//             arr[j]=ans[j];
//         }
//     }
// };

// Approach 2
// Time complexity -> O(n) and Space --> O(n)
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
    	
        
        int temp[n]; // Create an empty array to store result
     
        // Traversal array and store +ve element in temp array
        int j = 0; // index of temp
        for (int i = 0; i < n ; i++)
            if (arr[i] >= 0 )
                temp[j++] = arr[i];
     
       
        if (j == n || j == 0)  // If array contains all positive or all negative.
            return;
     
        // Store -ve element in temp array
        for (int i = 0 ; i < n ; i++)
            if (arr[i] < 0)
                temp[j++] = arr[i];
     
        // Copy contents of temp[] to arr[]
        memcpy(arr, temp, sizeof(temp));
        
    }
};



//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1