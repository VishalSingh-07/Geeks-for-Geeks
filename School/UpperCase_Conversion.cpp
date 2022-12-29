//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string transform(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<transform(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends



string transform(string s)
{
    // code here
    s[0]=toupper(s[0]);
    for(int i=0;i<s.length();i++)
    {
        if(s[i-1]==' ')
        {
            s[i]=toupper(s[i]);
        }
    }
    return s;
    
}
// Question Link -- https://practice.geeksforgeeks.org/problems/upper-case-conversion5419/1?page=1&difficulty[]=-2&status[]=solved&category[]=Strings&sortBy=submissions