//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Time complexity --> O(n) and Space --> O(n)
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        for(int i=0;i<x.length();i++)
        {
            if(st.empty())
            {
                // if the stack is empty just push the current bracket
                st.push(x[i]);
            }
            else if((st.top()=='(' && x[i]==')') 
                        || (st.top()=='{' && x[i]=='}') 
                        || (st.top()=='[' && x[i]==']'))
            {
                // if we found any complete pair of bracket then pop
                st.pop();
            }
            else
            {
                st.push(x[i]);
            }
            
        }
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1