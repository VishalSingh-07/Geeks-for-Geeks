//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Method 1
// Time complexity --> O(n) and Space --> O(n)
// class Solution
// {
//     public:
//     //Function to check if brackets are balanced or not.
//     bool ispar(string x)
//     {
//         // Your code here
//         stack<char> st;
//         for(int i=0;i<x.length();i++)
//         {
//             if(st.empty())
//             {
//                 // if the stack is empty just push the current bracket
//                 st.push(x[i]);
//             }
//             else if((st.top()=='(' && x[i]==')') 
//                         || (st.top()=='{' && x[i]=='}') 
//                         || (st.top()=='[' && x[i]==']'))
//             {
//                 // if we found any complete pair of bracket then pop
//                 st.pop();
//             }
//             else
//             {
//                 st.push(x[i]);
//             }
            
//         }
//         if(st.empty())
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }

// };

// Method 2
// Time complexity --> O(n) and Space --> O(n)
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
            }
            else
            {
                // if a closing bracket then we compare with the top of the stack 
                // while comparing with top of stack we have 2 cases 
                // the stack can be empty or the stack is not empty 

                if(st.empty())
                {
                    return false;
                }
                else
                {
                    if((st.top()=='(' && s[i]==')') 
                        || (st.top()=='[' && s[i]==']') 
                        || (st.top()=='{' && s[i]=='}'))
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }

                }

            }
        }
        if(st.empty())
        {
            return true;
        }
        
        return false;
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