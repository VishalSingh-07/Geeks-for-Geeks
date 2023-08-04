//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// Brute Force Approach [Using Array]
// Time complexity -> O(n) and Space -> O(n)
class Solution{
public:
    void Reverse(stack<int> &st){
        vector<int> arr;
        while(!st.empty())
        {
            arr.push_back(st.top());
            st.pop();
        }
        for(int i=0;i<arr.size();i++)
        {
            st.push(arr[i]);
        }
    }
};


// Better Approach [Using Stack]
// Time complexity -> O(n) and Space -> O(n)
class Solution{
public:
    void Reverse(stack<int> &st){
        stack<int> stk;
        while(!st.empty())
        {
            stk.push(st.top());
            st.pop();
        }
        st=stk;
    }
};


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution{
public:
    void Reverse(stack<int> &St){
        queue<int>q;
        while(!St.empty())
        {
            q.push(St.top());
            St.pop();
        }
        while(!q.empty())
        {
            St.push(q.front());
            q.pop();
        }
    }
};



//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/reverse-a-stack/1