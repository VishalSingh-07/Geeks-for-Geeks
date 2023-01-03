//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h> 
#include <vector> 
using namespace std; 

// } Driver Code Ends
class Solution
{
  public:
    vector<int> findIndex(int a[], int n, int key)
    {
        //code here.
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(a[i]==key)
            {
                ans.push_back(i);
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]==key)
            {
                ans.push_back(i);
                return ans;
            }
        }
        
        return {-1,-1};
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
        vector<int> res;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int key;
        cin>>key;
        Solution ob;
        res=ob.findIndex(arr, n, key);
        for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";
        cout << "\n";
    }
    
    return 0;
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/find-index4752/1?page=1&difficulty[]=-2&category[]=Arrays&sortBy=submissions