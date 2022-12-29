//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int a[],int n){
        // code here
        // First approach
        // int x=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(a[i]!=a[i+1])
        //     {
        //         a[x++]=a[i];
    
        //     }
        // }
        // return x;
        
        // Second Approach
        // set<int> s(a,a+n);
        // for(int i=0;i<n;i++)
        // {
        //     s.insert(a[i]);
        // }
        // int j=0;
        // for(auto i: s)
        // {
        //     a[j++]=i;
        // }
        // return s.size();
        
        // Two Pointer Approach
        int i=0;
        for(int j=1;j<n;j++)
        {
            if(a[j]!=a[i])
            {
                i++;
                a[i]=a[j]; 
            }
        }
        return i+1;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1?page=1&difficulty[]=0&status[]=solved&category[]=Arrays&sortBy=submissions