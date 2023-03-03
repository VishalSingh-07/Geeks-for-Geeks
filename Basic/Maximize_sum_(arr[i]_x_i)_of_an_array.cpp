//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(1)
class Solution{
    public:
    int Maximize(int arr[],int n)
    {
        // Complete the function
        sort(arr,arr+n);
        long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(long)arr[i]*i;
        }
        long ans=sum%1000000007;
        return (int) ans;
    }
};



//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1