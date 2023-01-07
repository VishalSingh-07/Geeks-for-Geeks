//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        bool check (string s)
        {
        	//code here.
        	
        	for(int i=0;i<s.length();i++)
        	{
        	    if(s[0]!=s[i])
        	    {
        	        return false;
        	    }
        	    
        	}
        	return true;
        	
        	
        }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
		string s;
		cin >> s;
		Solution ob;
		if (ob.check (s))
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/check-string1818/1