/*
Maximum Index

Given an array a of n positive integers. The task is to find the maximum of j - i subjected to the constraint of a[i] < a[j] and i < j.

Example 1:

Input:
n = 2
a[] = {1, 10}
Output:
1
Explanation:
a[0] < a[1] so (j-i) is 1-0 = 1.


Example 2:

Input:
n = 9
a[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output:
6
Explanation:
In the given array a[1] < a[7] satisfying the required condition(a[i] < a[j]) thus giving the maximum difference of j - i which is 6(7-1).


Your Task:
The task is to complete the function maxIndexDiff() which finds and returns maximum index difference. Printing the output will be handled by driver code. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ n ≤ 106
0 ≤ a[i] ≤ 109
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        // Your code here
        int maxIndex=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int index=0;
            for(int j=i;j<n;j++)
            {
                if(arr[i]<=arr[j])
                {
                    index=j-i;
                    maxIndex=max(maxIndex,index);
                }
            }
            
        }
        return maxIndex;
    }
};
// Above code give Time Limit Exceeded due to high complexity O(n^2)

// Better Approach
// Time complexity -> O(nlogn) and Space -> O(n)
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        // Your code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        int maxIndex=v[n-1].second;
        int maxdiff=0;
        for(int i=n-2;i>=0;i--)
        {
            maxIndex=max(maxIndex,v[i+1].second);
            maxdiff=max(maxdiff,maxIndex-v[i].second);
        }
        return maxdiff;
    }
};

// Better Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        // Your code here
        vector<int>left(n),right(n);
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        
        for(int i=1;i<n;i++)
        {
            left[i] = min(arr[i],left[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            right[i] = max(arr[i],right[i+1]);
        }
        int ans = 0,i=0,j=0;
        while(i<n && j<n)
        {
            if(left[i]<=right[j])
            {
                ans = max(ans,j-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends


// Question link -- https://www.geeksforgeeks.org/problems/maximum-index-1587115620/1