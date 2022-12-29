//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		long long int reverse_digit(long long int n)
		{
		    // Code here
		    long long int temp=n;
		    long long int rev=0,r;
		    while(temp>0)
		    {
		        r=temp%10;
		        rev=rev*10+r;
		        temp=temp/10;
		        
		    }
		    return rev;
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int n;
    	cin >> n;
    	Solution ob;
    	long long int  ans = ob.reverse_digit(n);
    	cout << ans <<"\n";
    }
	return 0;
}
// } Driver Code Ends

// Question Link --- https://practice.geeksforgeeks.org/problems/reverse-digit0316/1?page=1&difficulty[]=-2&status[]=solved&sortBy=submissions