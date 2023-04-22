/*
Smaller Sum
  
You are given an array arr of n integers. For each index i, you have to find the sum of all integers present in the array with a value less than arr[i].

Example 1:

Input:
n = 3
arr = {1, 2, 3}
Output:
0 1 3
Explanation:
For 1, there are no elements lesser than itself.
For 2, only 1 is lesser than 2.
And for 3, 1 and 2 are lesser than 3, so the sum is 3.


Example 2:

Input:
n = 2
arr = {4, 4}
Output:
0 0
Explanation:
For 4, there are no elements lesser than itself. 
For 4, there are no elements lesser than itself.
There are no smaller elements than 4.


Your Task:
You don't need to read input or print anything. Your task is to complete the function smallerSum() which takes an integer n and an array arr and returns an array of length n , the answer for every index.

Expected Time Complexity:O(n log n)
Expected Space Complexity:O(n)

Constraints:
1 <= n <= 105
0 <= arr[i] <= 109
*/

/*

*/

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(n)
// class Solution{
// public:
//     vector<long long> smallerSum(int n,vector<int> &arr){
//         // Code here
//         vector<long long> ans;
//         for(int i=0;i<n;i++)
//         {
//             long long sum=0;
//             for(int j=0;j<n;j++)
//             {
//                 if(arr[j]<arr[i])
//                 {
//                     sum+=arr[j];
//                 }
//             }
//             ans.push_back(sum);
//         }
//         return ans;
//     }
// };

// Above code give time limit Exceeded due to high complexity O(n^2)


// Better Approach[Binary Search]
// Time complexity -> O(nlogn) and Space -> O(n)
// class Solution{
// private:
//     int BinarySearch(int key,vector<int> &temp) // Lower Bound
//     {
//         int low=0,high=temp.size()-1;
//         int index=-1;
//         while(low<=high)
//         {
//             int mid=low+(high-low)/2;
//             if(temp[mid]>=key)
//             {
//                 index=mid;
//                 high=mid-1;
//             }
//             else
//             {
//                 low=mid+1;
//             }
//         }
//         return index;
//     }
    
    
// public:
//     vector<long long> smallerSum(int n,vector<int> &arr){
//         // Code here
//         vector<long long> ans(n),prefixSum(n);
//         vector<int> temp(n);
//         temp=arr;
//         sort(temp.begin(),temp.end());
//         prefixSum[0]=temp[0];
//         for(int i=1;i<n;i++)
//         {
//             prefixSum[i]=prefixSum[i-1]+temp[i];
//         }
//         for(int i=0;i<n;i++)
//         {
//             int index=BinarySearch(arr[i],temp);
//             ans[i]=prefixSum[index]-arr[i];
//         }
//         return ans;
//     }
// };


// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(n)
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<long long> ans;
        vector<int> temp;
        temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<long long, long long> mp;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(temp[i])==mp.end())
            {
                mp[temp[i]]=sum;
            }
            sum+=temp[i];
        }
        for(int i=0;i<n;i++)
        {
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/5877fde1c8e1029658845cd4bc94066ac1d4b09b/1


// Solution link -- https://discuss.geeksforgeeks.org/comment/67b5d5f7e2befb45af81a5c8f61ef642