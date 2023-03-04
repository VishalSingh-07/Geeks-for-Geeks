//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends



// Brute Force Approach 
// Time complexity -> O(n*m) and Space -> O(1)
/*
where 
    m= length of string s
    n= length of string x
*/

//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
    int m=s.length();
    int n=x.length();
    
    if(n==0)
    {
        return -1;
    }
    if(m<n)
    {
        return -1;
    }
    for(int i=0;i<=m-n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(x[j]==s[j+i])
            {
                count++;
            }
        }
        if(count==n)
        {
            return i;
        }
        
    }
    return -1;
}

///OR---

int strstr(string s, string x)
{
     //Your code here
    int m=s.length();
    int n=x.length();
    
    if(n==0)
    {
        return -1;
    }
    if(m<n)
    {
        return -1;
    }
    for(int i=0;i<=m-n;i++)
    {
        bool isCheck=true;
        for(int j=0;j<n;j++)
        {
            if(x[j]!=s[j+i])
            {
                isCheck=false;
            }
        }
        if(isCheck)
        {
            return i;
        }
        
    }
    return -1;
}


// Optimized Approach  [Inbuilt Function]

// Time complexity -> O(n+m) and Space -> O(1)
/*
where 
    m= length of string s
    n= length of string x
*/

//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
     size_t found=s.find(x);
     if(found!=string::npos)
     {
         return found;
     }
     return -1;
}


/*
1. Question link -- https://practice.geeksforgeeks.org/problems/implement-strstr/1

2. Solution link --

      i) https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/3252629/2-approach-easy-c-solution-brute-force-and-optimized-approach/

      ii) https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/3249831/day-62-o-m-n-time-o-m-space-kmp-algo-easiest-beginner-friendly-sol/

3. Video link -- https://youtu.be/_ZWnkyae2gA
*/