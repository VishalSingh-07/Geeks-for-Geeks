//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}


// } Driver Code Ends


// Approach 1: Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    char *str =new char[len];
    for(int i=0;i<len;i++)
    {
        str[i]=S[len-i-1];
    }
    return str;
}

// Approach 2: Using Reverse Function
// Time complexity -> O(nlogn) and Space -> O(1)
//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    reverse(S,S+len);
    return S;
}


// Approach 3: Two Pointer Approach
// Time complexity -> O(n/2) and Space -> O(1)
//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    int i,j;
    for(i=0,j=len-1;i<j;i++,j--)
    {
        swap(S[i],S[j]);
    }
    return S;
}

// OR
//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    int i=0,j=len-1;
    while(i<j)
    {
        swap(S[i++],S[j--]);
    }
    return S;
}

// Above all approach are not allowed according to the question but it is correct to reverse a string

// Approach 4: Using Stack
// Time complexity -> O(n) and Space -> O(n)
//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    stack<char> st;
    char *str= new char[len];
    for(int i=0;i<len;i++)
    {
        st.push(S[i]);
    }
    int j=0;
    while(!st.empty())
    {
        str[j++]=st.top();
        st.pop();
    }
    return str;
}

// OR ---------

// return the address of the string
char* reverse(char *S, int len)
{
    //code here
    stack<char> st;
    for(int i=0;i<len;i++)
    {
        st.push(S[i]);
    }
    int j=0;
    while(!st.empty())
    {
        S[j++]=st.top();
        st.pop();
    }
    return S;
}


// Question link --https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1