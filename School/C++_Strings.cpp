//{ Driver Code Starts
#include<iostream>
#include<string>
using namespace std;

string conCat(string a , string b);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        cout<<conCat(a,b)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string conCat(string s1 , string s2)
{
    // code here.
    string result=s1+s2;
    return result;
}

// Question Link -- https://practice.geeksforgeeks.org/problems/c-strings4609/1?page=1&difficulty[]=-2&status[]=solved&category[]=Strings&sortBy=submissions