//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int missingNumber(int a[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i=0, n;
		cin>>n;
		int a[n+5];
		for(i=0;i<n-1;i++)
			cin>>a[i];
			
		cout<<missingNumber(a, n)<<endl;
	}
}
// } Driver Code Ends

int missingNumber(int A[], int N)
{
    // Your code goes here
    int sum=N*(N+1)/2;
    int array_sum=0;
    int missing_number;
    
    for(int i=0;i<N-1;i++)
    {
        array_sum=array_sum + A[i];
    }
    if(array_sum==sum)
    {
        return -1;
    }
    else
    {
        missing_number=sum-array_sum;
        return missing_number;
        
    }
    
}
// Question Link -- https://practice.geeksforgeeks.org/problems/missing-number4257/1?page=1&difficulty[]=-1&status[]=solved&category[]=Arrays&sortBy=submissions