//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Brute Force Approach
// Time complexity -->O(n^2) and Space --> O(1)
// class Solution{
//     public:
//     long long solve(int arr[], int n){
//         // your code here
//         long long count=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(arr[i]<arr[j])
//                 {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

// Above code give Time limit Exceeded [Time complexity -->O(n^2)]


// Binary Search Approach
// Time complexity -->O(nlogn) and Space --> O(1)
// class Solution{
//     public:
//     int findNolesser(int arr[], int n, int key)
//     {
//         int low=0;
//         int high=n-1;
//         int ans=-1;
        
//         while(low<=high)
//         {
//             int mid=low+(high-low)/2;
            
//             if(arr[mid]==key)
//             {
//                 ans=mid;
//                 high=mid-1;
//             }
//             else if(arr[mid]>key)
//             {
//                 high=mid-1;
//             }
//             else
//             {
//                 low=mid+1;
//             }
//         }
//         return ans;
//     }
//     long long solve(int arr[], int n){
//         // your code here
//         long long count=0;
//         sort(arr,arr+n);
//         for(int i=0;i<n;i++)
//         {
//             int x=findNolesser(arr,n,arr[i]);
//             count+=(x==-1?0:x);
//         }
//         return count;
//     }
// };

// Optimized Approach
// Time complexity --> O(n) and Space --> O(1)
class Solution{
    public:
    long long solve(int arr[], int n){
        // your code here
        map<int,int> m;
        long long count=0,sum=0;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        for(auto it: m)
        {
            sum+=it.second;
            count+=(n-sum)*it.second;
        }
        
        return count;
        
        
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        int arr[n];
        for(int i = 0; i<n; i++)
            cin >> arr[i];
        Solution ob;
        long long ans = ob.solve(arr,n);
        cout << ans << endl;
    }
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/good-pairs4519/1