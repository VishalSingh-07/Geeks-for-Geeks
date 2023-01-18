//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
  public:   
    int countCamelCase (string s)
    {
    	//code here.
    	int count=0;
    	for(int i=0;i<s.length();i++)
    	{
    	    if(s[i]>=65 && s[i]<=90)
    	    {
    	        count++;
    	    }
    	}
    	return count;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout <<ob.countCamelCase (s) << '\n';
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/find-the-camel3348/1