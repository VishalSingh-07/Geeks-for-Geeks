//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    string longest(string names[], int n)
    {
        int max=0;
        for(int i=1;i<n;i++)
        {
            if(names[i].length()>names[max].length())
            {
                max=i;
            }
            
            
        }
        return names[max];
        
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
		string names[n];
		
		for(int i=0;i<n;i++)
			cin>>names[i];
		Solution ob;
		cout<< ob.longest(names, n) << endl;
	}
}

// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/display-longest-name0853/1?page=1&difficulty[]=-2&status[]=solved&category[]=Strings&sortBy=submissions