//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

// Time complexity --> O(n) and Space -> O(1)
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here

	    string ans="";
	    int h[256]={0};
	    for(int i=0;i<str.length();i++)
	    {
	        if(h[str[i]]==0)
	        {
	            ans+=str[i];
	            h[str[i]]++;
	        }
	        
	    }
	    return ans;
	}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1
