//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        int i, h[26]={0};
        for(i=0;a[i]!='\0';i++)
        {
            h[a[i]-97]++;
        }
        for(i=0;b[i]!='\0';i++)
        {
            h[b[i]-97]--;
            if(h[b[i]-97]<0)
            {
                return false;
                break;
            }
        }
        if(b[i]=='\0')
        {
            return true;
        }
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends


// Question Link -- https://practice.geeksforgeeks.org/problems/anagram-1587115620/1?page=1&difficulty[]=0&status[]=solved&category[]=Strings&sortBy=submissions