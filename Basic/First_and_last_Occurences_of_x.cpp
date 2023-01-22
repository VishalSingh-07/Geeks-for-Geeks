//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Brute Force Approach
// Time complexity --> O(n) and space --> O(n)
// vector<int> find(int arr[], int n , int x )
// {
//     // code here
//     vector<int> v;
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]==x)
//         {
//             v.push_back(i);
//             break;
//         }
        
//     }
//     for(int i=n-1;i>0;i--)
//     {
//         if(arr[i]==x)
//         {
//             v.push_back(i);
//             break;
//         }
        
//     }
//     if(v.empty())
//     {
//         v.push_back(-1);
//         v.push_back(-1);
//     }
//     return v;
// }


// Optimized Approach 
// Time complexity --> O(logn) and Space --> O(1)
vector<int> find(int arr[], int n , int x )
{
    int index1=-1;
    int index2=-1;
    int low=0;
    int high=n-1;
    while(low<=high) // for searching an element on the left side of an array
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==x)
        {
            index1=mid;
            high=mid-1;
        }
        else if(arr[mid]>x) // move to left
        {
            high=mid-1;
        }
        else // move to right
        {
            low=mid+1;
        }
    }
    
    low=0;
    high=n-1;
    while(low<=high) // for searching an element on the right side of an array
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==x)
        {
            index2=mid;
            low=mid+1;
        }
        else if(arr[mid]>x)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(index1==-1 && index2==-1)
    {
        return {-1,-1};
    }
    return {index1, index2};
}



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1?page=1&difficulty[]=-1&status[]=solved&category[]=Arrays&sortBy=submissions