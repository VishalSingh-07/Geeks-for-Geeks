/*
Find the Highest number

Given an integer array a[] of size n, find the highest element of the array. The array will either be strictly increasing or strictly increasing and then strictly decreasing.

Note: a[i] != a[i+1] 

Example 1:

Input:
11
1 2 3 4 5 6 5 4 3 2 1
Output: 
6
Explanation: 
Highest element of array a[] is 6.


Example 2:

Input:
5
1 2 3 4 5
Output:
5
Explanation: 
Highest element of array a[] is 5.


Your Task:
- You don't need to read or print anything. Your task is to complete the function findPeakElement() which takes integer n, and the array a[] as the input parameters and returns the highest element of the array.

Expected Time Complexity: O(log(n))
Expected Space Complexity: O(1)

Constraints:
- 2 <= n <= 106
- 1 <= a[i] <= 106
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        int maxi=INT_MIN;
        for(int i=0;i<a.size();i++){
            if(a[i]>maxi){
                maxi=a[i];
            }
        }
        return maxi;
    }
};


// Optimized Approach
// Time complexity -> O(logn) and Space -> O(1)
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        int start=0;
        int end=a.size()-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(a[mid]<a[mid+1]){
                start=mid+1;
            }else{
                end=mid;
            }
        }
        return a[start];
    }
};




//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends


/*
1. Question link -- https://www.geeksforgeeks.org/problems/find-the-highest-number2259/1

2. Solution link -- https://leetcode.com/problems/peak-index-in-a-mountain-array/solutions/3044985/best-solution-three-approach-to-solve-a-problem-linear-search-stl-max-element-binary-search
*/