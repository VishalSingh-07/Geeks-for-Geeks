//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    int PalinArray(int a[], int n)
    {
    	// code here
    	int count=0,temp;
    	for(int i=0;i<n;i++)
    	{
    	    temp=a[i];
    	    int rev=0,r;
    	    while(temp!=0)
    	    {
    	        r=temp%10;
    	        rev=(rev*10)+r;
    	        temp=temp/10;
    	    }
    	    if(a[i]==rev)
    	    {
    	        count++;
    	    }
    	    else
    	    {
    	        return 0;
    	    }
    	        
    	}
    	if(count==n)
    	{
    	    return 1;
    	}
    	else
    	{
    	    return 0;
    	}
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
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends

// Question Link: -- https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1?page=1&difficulty[]=-2&status[]=solved&category[]=Arrays&sortBy=submissions