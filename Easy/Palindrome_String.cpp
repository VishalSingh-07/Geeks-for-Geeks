//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// Brute Force Approach 
// Time complexity -> O(n) and Space -> O(n)
// class Solution{
// public:	
	
	
// 	int isPalindrome(string S)
// 	{
// 	    // Your code goes here
// 	    string rev="";
// 	    for(int i=S.size()-1;i>=0;i--)
// 	    {
// 	        rev+=S[i];
// 	    }
// 	    return S==rev;
// 	}

// };


// Better Approach
// Time complexity -> O(n/2) and Space -> O(n)
//User function template for C++
// class Solution{
// public:	
// 	int isPalindrome(string S)
// 	{
// 	    // Your code goes here
// 	    string temp=S;
// 	    int n=S.length();
// 	    for(int i=0;i<n/2;i++)
// 	    {
// 	        swap(S[i],S[n-i-1]);
// 	    }
// 	    if(S==temp)
// 	    {
// 	        return 1;
// 	    }
// 	    else
// 	    {
// 	        return 0;
// 	    }
	    
// 	}

// };


// Optimized approach
// Time complexity -> O(n) and Space -> O(1)
//User function template for C++
class Solution{
public:	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int left=0, right=S.length()-1;
	    
	    while(left<=right)
	    {
	        if(S[left]!=S[right])
	        {
	            return 0;
	        }
	        left++;
	        right--;
	    }
	    return 1;
	    
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

// Question Link -- https://practice.geeksforgeeks.org/problems/palindrome-string0817/1