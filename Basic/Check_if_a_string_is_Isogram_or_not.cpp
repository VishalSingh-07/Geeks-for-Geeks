//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if a string is Isogram or not.
    bool isIsogram(string s)
    {
        //Your code here
        int n=s.length();  // length of the string
        for(int i=0;i<n;i++)
        {
            s[i]=tolower(s[i]); // converting string into lower case
        }
        sort(s.begin(),s.end());
        
        for(int i=0;i<n;i++)
        {
            if(s[i]==s[i+1])
            {
                return false;
            }
        }
        return true;
    }
};

// Solution using hash table
// class Solution
// {
//     public:
//     //Function to check if a string is Isogram or not.
//     bool isIsogram(string s)
//     {
//         int hash[26]={0};
        
//         //iterating over the string.
//         for(int i=0;i<s.length();i++)
//         {
//             //incrementing the count of characters in hash table.
//             hash[s[i]-'a']++;
            
//             //if count of any character is greater than 1 then 
//             //string is not isogram so we return false.
//             if(hash[s[i]-'a']>1)
//             return false;
//         }
//         //returning true if no character occurs more than once.
//         return true;
//     }

// };


//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.isIsogram(s)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/check-if-a-string-is-isogram-or-not-1587115620/1?page=1&difficulty[]=-1&status[]=solved&category[]=Strings&sortBy=submissions