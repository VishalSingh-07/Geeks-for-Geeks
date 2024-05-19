/*
Find the closest number

Given a sorted array arr[] of positive integers. The task is to find the closest value in the array to the given number k. The array may contain duplicate values.

Note: If the difference with k is the same for two values in the array return the greater value.

Example 1:

Input: 
n = 4
k = 4
arr[] = {1, 3, 6, 7}
Output: 
3
Explanation:
We have array arr={1, 3, 6, 7} and target is 4. If we look at the absolute difference of target with every element of the array we will get { |1-4|, |3-4|, |6-4|, |7-4| }  = {3, 1, 2, 3}. So, the closest number is 3.



Example 2:

Input:
n = 7
k = 4
arr[] = {1, 2, 3, 5, 6, 8, 9}
Output:
5
Explanation:
The absolute difference of 4 is 1 from both 3 and 5. According to the question, we have to return greater value, which is 5.


Your Task:
- This is a function problem. The input is already taken care of by the driver code. You only need to complete the function findClosest() that takes integers n and k and sorted array arr[] of size n as input parameters and return the closest number in the array to k. 

Expected Time Complexity: O(log(n)).
Expected Auxiliary Space: O(1).

Constraints:
- 1 ≤ n ≤ 106
- 1 ≤ k ≤ 109
- 1 ≤ arr[i] ≤ 109
*/


//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int minDiff=INT_MAX;
        int closestElement=0;
        for(int i=0;i<n;i++){
            int diff=abs(k-arr[i]);
            if(diff<=minDiff){
                minDiff=diff;
                closestElement=max(closestElement,arr[i]);
            }
        }
        return closestElement;
    } 
};


// Optimized Approach [Binary Search]
// Time complexity -> O(logn) and Space -> O(1)
class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int start=0;
        int end=n-1;
        int ele1=0,ele2=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(arr[mid]<=k){
                ele1=arr[mid];
                start=mid+1;
            }
            else{
                ele2=arr[mid];
                end=mid-1;
            }
        }
        return (abs(ele1-k)<abs(ele2-k))?ele1:ele2;
        
    } 
};


//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/find-the-closest-number5513/1