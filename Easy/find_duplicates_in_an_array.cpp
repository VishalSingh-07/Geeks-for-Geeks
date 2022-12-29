//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector <int> duplicates(int arr[], int n)
    {
        for(int i=0; i<n; i++)
        {
            int val=arr[i] % n;
            arr[val] += n;
        }
        vector <int> ans;
        for(int i=0; i<n; i++)
        {
            arr[i] /= n;
            if(arr[i]>1)
            {
                ans.push_back(i);
            }
            
        }
        if(ans.size()==0)
        {
                ans.push_back(-1);
        }
        return ans;
    }
    // int max(int arr[], int n)
    // {
    //     int max=arr[0];
    //     for(int i=0; i< n;i++)
    //     {
    //         if(max<arr[i])
    //         {
    //             max=arr[i];
    //         }
    //     }
    //     return max;
        
    // }
    // int min(int arr[], int n)
    // {
    //     int min=arr[0];
    //     for(int i=0; i<n;i++)
    //     {
    //         if(min>arr[i])
    //         {
    //             min=arr[i];
    //         }
    //     }
    //     return min;
        
    // }
    // vector<int> duplicates(int arr[], int n) {
    //     // code here
    //     vector <int> ans;
    //     int h=max(arr,n);
    //     int l=min(arr,n);
    //     int H[h+1]={0};
        
    //     for(int i=0;i<n;i++)
    //     {
    //         H[arr[i]]++;
    //     }
    //     for(int i=l;i<h+1;i++)
    //     {
    //         if(H[i]>1)
    //         {
    //             ans.push_back(i);
    //         }
    //         else
    //         {
    //             ans.push_back(-1);
    //         }

    //     }
        
        
    // }
    
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1?page=1&difficulty[]=0&status[]=solved&category[]=Arrays&sortBy=submissions