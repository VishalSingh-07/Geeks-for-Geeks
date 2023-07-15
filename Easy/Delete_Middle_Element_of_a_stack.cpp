//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

// Brute Force Approach
// Time complexity -> O(2n) and Space -> O(n)
// class Solution
// {
//     public:
//     //Function to delete middle element of a stack.
//     void deleteMid(stack<int>&s, int sizeOfStack)
//     {
//         // code here.. 
//         int middle_element=sizeOfStack/2;
//         vector<int> v;
//         for(int i=0;i<sizeOfStack;i++)
//         {
//             if(middle_element!=i)
//             {
//                 v.push_back(s.top());
//             }
//             s.pop();
//         }
//         for(int i=v.size()-1;i>=0;i--)
//         {
//             s.push(v[i]);
//         }
        
//     }
// };


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution
{
    public:
    void rec(stack<int> &s, int index, int mid)
    {
        if(index==mid) // base condition
        {
            s.pop();
            return;
        }
        int temp=s.top();
        s.pop();
        rec(s,index+1,mid); // call the recursion
        s.push(temp); // push all the elements again to the stack
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int middle_element=sizeOfStack/2;
        rec(s,0,middle_element);
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1