//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    string temp=S;
	    int n=S.length();
	    for(int i=0;i<n/2;i++)
	    {
	        swap(S[i],S[n-i-1]);
	    }
	    if(S==temp)
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
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/palindrome-string0817/1?page=1&difficulty[]=0&status[]=solved&category[]=Strings&sortBy=submissions