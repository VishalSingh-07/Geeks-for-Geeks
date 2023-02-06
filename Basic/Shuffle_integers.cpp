//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// Brute Force Approach
// Time complexity --> O(n) and Space --> O(n)
// class Solution{
// 	public:
// 	void shuffleArray(int arr[],int n)
// 	{
// 	    // Your code goes here
// 	    vector<int> ans(n,0);
// 	    int x=0;
// 	    for(int i=0;i<n/2;i++)
// 	    {
// 	        ans[x]=arr[i];
// 	        x+=2;
// 	    }
	    
// 	    x=1;
// 	    for(int i=n/2;i<n;i++)
// 	    {
// 	        ans[x]=arr[i];
// 	        x+=2;
// 	    }
// 	    for(int i=0;i<n;i++)
// 	    {
// 	        arr[i]=ans[i];
// 	    }
	    
// 	}
		 

// };

// Two pointer Approach
// Time complexity --> O(n) and Space --> O(n)
// class Solution{
// 	public:
// 	void shuffleArray(int arr[],int n)
// 	{
// 	    // Your code goes here
// 	   vector<int> ans;
// 	   for(int i=0,j=n/2;i<n,j<n;i++,j++)
// 	   {
// 	       ans.push_back(arr[i]);
// 	       ans.push_back(arr[j]);
// 	   }
// 	   for(int x=0;x<n;x++)
// 	   {
// 	       arr[x]=ans[x];
// 	   }
// 	}
		 

// };


// Optimized Approach
// Time complexity --> O(n) and Space --> O(1)
class Solution{
	public:
	void shuffleArray(int arr[],int n)
	{
	    // Your code goes here
	    int max=10000;
	    int m=n/2;
	   for(int i=0;i<m;i++)
	   {
	       arr[i+m]+=arr[i]*max;
	   }
	   for(int i=0;i<m;i++)
	   {
	       arr[2*i]=arr[i+m]/max;
	       arr[2*i+1]=arr[i+m]%max;
	   }
	}
		 

};

// max value can varies from greater than 1000, you also take 1001, it work perfectly.


//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends





// Question link -- https://practice.geeksforgeeks.org/problems/shuffle-integers2401/1

// Video link -- https://youtu.be/XzU5nV98W40

// My Solution link -- https://leetcode.com/problems/shuffle-the-array/solutions/3150564/3-approach-to-solve-a-problem-easy-c-solution-brute-force-two-pointer-optimized/