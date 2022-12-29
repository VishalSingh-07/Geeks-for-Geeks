//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    long long findMissing(long long a[], long long b[], int n)
    {
        long long int count1=0,count2=0;
        for(int i=0;i<n;i++)
        {
            count1=count1+a[i];
        }
        for(int i=0;i<n-1;i++)
        {
            count2=count2+b[i];
        }
        
        return count1-count2;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long a[n], b[n-1];

        for(int i=0;i<n;i++){
          cin>>a[i];
        }
        for(int i=0;i<n-1;i++){
          cin>>b[i];
        }
        Solution ob;
        cout<<ob.findMissing(a, b, n)<<endl;
    }
}


// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/missing-number-in-shuffled-array0938/1?page=1&difficulty[]=-1&status[]=solved&category[]=Arrays&sortBy=submissions