//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
//User function template for C++
// class Solution{
// public:	
		
// 	string removeDups(string s) 
// 	{
// 	    // Your code goes here
// 	    set<char> st;
// 	    string res="";
// 	    for(auto ch: s)
// 	    {
// 	        if(st.find(ch)==st.end())
// 	        {
// 	            res+=ch;
// 	            st.insert(ch);
// 	        }
// 	    }
// 	    return res;
// 	}
// };


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
//User function template for C++
class Solution{
public:	
		
	string removeDups(string s) 
	{
	    // Your code goes here
	    int h[26]={0};
	    string res="";
	    for(int i=0;i<s.size();i++)
	    {
	        if(h[s[i]-'a']==0)
	        {
	            res+=s[i];
	        }
	        h[s[i]-'a']++;
	    }
	    return res;
	    
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
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/remove-duplicates3034/1