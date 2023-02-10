//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram

// Time Complexity: O(max(|S1|, |S2|)), where |S| = length of string S.
// Space Complexity: O(26)

int remAnagram(string str1, string str2)
{
    // Your code goes here
    int count1[26]={0};
    int count2[26]={0};
    
    for(int i=0;i<str1.length();i++)
    {
        count1[str1[i]-97]++;
    }
    for(int i=0;i<str2.length();i++)
    {
        count2[str2[i]-97]++;
    }
    int ans=0;
    for(int i=0;i<26;i++)
    {
        ans+=abs(count1[i]-count2[i]);
    }
    return ans;
}


// Question link -- https://practice.geeksforgeeks.org/problems/anagram-of-string/1