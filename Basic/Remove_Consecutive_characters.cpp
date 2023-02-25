//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends

// Approach 1: Using stack
// Time complexity --> O(n) and Space --> O(n)
// where n= |S|
class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        // code here.
        stack<char> ans;
        string res;
        for(int i=0;i<s.length();i++)
        {
            if(ans.empty())
            {
                ans.push(s[i]);
            }
            else if(ans.top()==s[i])
            {
                continue;
            }
            else
            {
                ans.push(s[i]);
            }
        }
        while(!ans.empty())
        {
            res=res+ans.top();
            ans.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }

};

// Approach 2: Simple Approach
// Time complexity --> O(n) and Space --> O(n)
// where n= |S|
// class Solution{
//     public:
//     string removeConsecutiveCharacter(string s)
//     {
//         // code here.
//         string ans="";
//         ans+=s[0];
//         for(int i=1;i<s.length();i++)
//         {
//             if(s[i]!=s[i-1])
//             {
//                 ans+=s[i];
//             }
//         }
//         return ans;
//     }

// };


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1