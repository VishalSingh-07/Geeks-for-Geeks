/*
First element to occur k times

Given an array of n integers. Find the first element that occurs atleast k number of times.

Example 1:

Input :
n = 7, k = 2
a[] = {1, 7, 4, 3, 4, 8, 7}
Output :
4
Explanation :
Both 7 and 4 occur 2 times. But 4 is first that occurs twice.
As at index = 4, 4 has occurred twice whereas 7 appeared twice
at index 6.


Example 2:

Input :
n = 10, k = 3
a[] = {3, 1, 3, 4, 5, 1, 3, 3, 5, 4}
Output :
3
Explanation :
Here, 3 is the only number that appeared atleast 3 times in the array.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function firstElementKTime() which takes the array a[], its size n, and an integer k as input arguments and returns the required answer. If the answer is not present in the array, return -1.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 104
1 <= k <= 100
0<= a[i] <= 200
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(n)
class Solution{
    public:
    int firstElementKTime(int n, int k, int arr[])
    {
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            mpp[arr[i]]++;
            for(auto it: mpp)
            {
                if(it.second>=k)
                {
                    return it.first;
                }
            }
        }
        return -1;
    }
};

// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution{
    public:
    int firstElementKTime(int n, int k, int arr[])
    {
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            mpp[arr[i]]++;
            if(mpp[arr[i]]>=k)
            {
                return arr[i];
            }
        }
        return -1;
    }
};




//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(n, k, a)<<endl;
	}
	
	return 0;
}

// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1