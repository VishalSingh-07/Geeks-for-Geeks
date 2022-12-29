//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    // Code here.
		    int sum=0,r,temp;
		    temp=n;
		    
		    while(n>0)
		    {
		        r=n%10;
		        sum=(sum*10)+r;
		        n=n/10;
		    }
		    if(temp==sum)
		    {
		        return "Yes";
		    }
		    else
		    {
		        return "No";
		    }
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends

// Question Link --- https://practice.geeksforgeeks.org/problems/palindrome0746/1?page=2&difficulty[]=-2&status[]=solved&sortBy=submissions