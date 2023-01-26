//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


// Using Hash Map approach
// Time complexity --> O(n) and Space --> O(n)
string firstRepChar(string s)
{
    //code here.
    unordered_map<char,int> mp;
    string res="";
    for(int i=0;i<s.length();i++)
    {
        mp[s[i]]++;
        if(mp[s[i]]>1)
        {
            res+=s[i];
            return res;
        }
    }
    return "-1";
}

// Using Set Approach
// Time complexity --> O(n) and Space --> O(n)
string firstRepChar(string s)
{
    //code here.
    unordered_set<char> set;
    string ans="";
    // Traverse the input array from left to right
    for(int i=0;i<s.length();i++)
    {
        
        // if element is already in hash set, update x and then break
        if(set.find(s[i])!=set.end())
        {
            ans=ans+s[i];
            return ans;
        }
        else // else add element to hash set
        {
            set.insert(s[i]);
        }
    }
    return "-1";
}

// Optimized Code
// Time complexity-> O(|S|) and Space --> O(1)
// Where |S| denotes the length of string s
string firstRepChar(string s)
{
    //code here
    int ar[26]={0};
    string res="";
    for(int i=0;i<s.length();i++)
    {
        ar[s[i]-97]++;
        if(ar[s[i]-97]==2)
        {
            res=res+s[i];
            return res;
        }
    }
    return "-1";
}

// Question link -- https://practice.geeksforgeeks.org/problems/find-first-repeated-character4108/1