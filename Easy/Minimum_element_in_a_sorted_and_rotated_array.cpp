/*
Minimum element in a sorted and rotated array

A sorted(in ascending order) array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

Example 1

Input:
N = 5
arr[] = {4 ,5 ,1 ,2 ,3}
Output: 1
Explanation: 1 is the minimum element inthe array.


Example 2

Input:
N = 7
arr[] = {10, 20, 30, 40, 50, 5, 7}
Output: 5
Explanation: Here 5 is the minimum element.
 

Your Task:
Complete the function findMin() which takes an array arr[] and n, size of the array as input parameters, and returns the minimum element of the array.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(log N).

Constraints:
1 ≤ N ≤ 100000
1 ≤ A[i] ≤ 1000000
*/
//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(1)
// class Solution{
// public:
//     int findMin(int arr[], int n){
//         //complete the function here
//         int min=INT_MAX;
//         for(int i=0;i<n;i++)
//         {
//             if(arr[i]<min)
//             {
//                 min=arr[i];
//             }
//         }
//         return min;
//     }
// };

// Optimized Approach
// Time complexity -> O(logn) and Space -> O(1)
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        if(n==1)
        {
            return arr[0];
        }
        int start=0,end=n-1;
        if(arr[0]<arr[end])
        {
            return arr[0];
        }
        while(start<=end)
        {
            int mid=start+(end-start)/2; // Finding the mid element
            
            
            /* 
            If the mid element is greater than its next element then 
            mid+1 element is the smallest. This point would be the point 
            of change [Inflection Point]. */    
            if(arr[mid]>arr[mid+1])
            {
                return arr[mid+1];
            }
            /* 
            If the mid element is lesser than its previous element then mid 
            element is the smallesT.This point would be the point of change 
            [Inflection Point]. */
            if(arr[mid]<arr[mid-1])
            {
                return arr[mid];
            }
            /* 
            If the mid element is greater than 0th element this means 
            the least value is still somewhere to the right as we are still 
            dealing with elements greater thn nums[0]. [Right Search] */
            if(arr[mid]>arr[0])
            {
                start=mid+1;
            }
            
            /* 
            If nums[0] is greater than the mid value then this means 
            the smallest value is somewhere to the left [Left Search] 
            */
            else
            {
                end=mid-1;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*
1. Question link -- https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1

2. Solution Link -- 
      a) https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solutions/3340231/2-approach-easy-c-solution-brute-force-optimized-approach-fully-explained/
      b) https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/editorial/
*/