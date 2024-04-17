/*
Count Pairs in an Array

Given an array arr of n integers, count all pairs (arr[i], arr[j]) in it such that i*arr[i] > j*arr[j] and 0 ≤ i < j < n.

Note: 0-based Indexing is followed.

Example 1:

Input :
n = 4
arr[] = {8, 4, 2, 1}
Output :
2
Explanation:
If we see the array after operations
[0*8, 1*4, 2*2, 3*1] => [0, 4, 4, 3]
Pairs which hold the condition i*arr[i] > j*arr[j] are (4,1) and (2,1), so in total 2 pairs are available.




Example 2:

Input :
n = 7
arr[] = {5, 0, 10, 2, 4, 1, 6}
Output:
5
Explanation :
Pairs which hold the condition i*arr[i] > j*arr[j] are (10,2), (10,4), (10,1), (2,1) and (4,1), so in total 5 pairs are there.


Your Task:  
You don't need to read input or print anything. Your task is to complete the function countPairs() which takes the array arr[] and its size n as inputs and returns the required result.

Expected Time Complexity: O(n*log(n))
Expected Auxiliary Space: O(n*log(n))

Constraints:
1 ≤ n ≤ 104
0 ≤ arr[i] ≤ 104
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(n^2)
class Solution{
    public:
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here 
        vector<pair<int,int>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i*arr[i]>j*arr[j]){
                    ans.push_back(make_pair(arr[i],arr[j]));
                }
            }
        }
        return ans.size();
    }
};

// Above Code give Time Limit Exceeded due to high complexity O(n^2)


// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(nlogn)

class Solution{
    int merge(int arr[], int low, int mid, int high)
    {
        vector<int> temp;
        int left=low;
        int right=mid+1LL;
        int count=0;
        while(left<=mid && right<=high)
        {
            if(arr[left]<=arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                count+=(mid-left+1);
                right++;
            }
        }
        while(left<=mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high)
        {
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low;i<=high;i++)
        {
            arr[i]=temp[i-low];
        }
        return count;
    }
    int mergeSort(int arr[], int low,int high)
    {
        int count=0;
        if(low>=high)
        {
            return count;
        }
        int mid= low + (high - low) / 2;
        count+=mergeSort(arr,low,mid);
        count+=mergeSort(arr,mid+1,high);
        count+=merge(arr,low,mid,high);
        return count;
    }
    public:
    int countPairs(int arr[] , int n ) 
    {
        for(int i=0;i<n;i++){
            arr[i]*=i;
        }
        return mergeSort(arr,0,n-1);
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
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
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends

/*
1. Question link -- https://www.geeksforgeeks.org/problems/count-pairs-in-an-array4145/1

2. Solution link -- https://github.com/VishalSingh-07/Striver-SDE-Sheet-Notes/blob/master/Day%202%20-%20Arrays%20Part-II/Count%20Inversions.md
*/