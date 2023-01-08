//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Time complexity -->O(n) and Space ---> O(n)
class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        map<char,int>mp;
        for(int i=0;i<str.size();i++)
        {
            mp[str[i]]++;
        }
        int maxi=-1;
        for(auto it: mp) // find max apperance element in the array
        {
            maxi=max(it.second,maxi);
        }
        for(auto it: mp)
        {
            if(it.second==maxi)
            {
                return it.first;
            }
        }
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends


// Question link -- https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1