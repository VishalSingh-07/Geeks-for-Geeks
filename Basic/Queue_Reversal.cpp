//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++


// Brute Force Approach
// Time complexity -> O(2n) and Space -> O(n)
//Function to reverse the queue.
// class Solution
// {
//     public:
//     queue<int> rev(queue<int> q)
//     {
//         // add code here.
//         vector<int> v;
//         while(!q.empty())
//         {
//             v.push_back(q.front());
//             q.pop();
//         }
//         for(int i=v.size()-1;i>=0;i--)
//         {
//             q.push(v[i]);
//         }
//         return q;
//     }
// };


// Optimized Approach [Recursive]
// Time complexity -> O(n) and Space -> O(n)
//Function to reverse the queue.
class Solution
{
    public:
    void recQue(queue<int> &q)
    {
        if(!q.size())
        {
            return;
        }
        
        int head=q.front(); // fetch head of queue
        q.pop(); // remove head
        recQue(q); // recursion to remove last element as head
        q.push(head); // adding from last element as first head every time after recursion
    }
    
    queue<int> rev(queue<int> q)
    {
        // add code here.
        
        recQue(q);
        
        return q;
    }
};








//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/queue-reversal/1