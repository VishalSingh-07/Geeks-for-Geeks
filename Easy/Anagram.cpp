//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Brute Force Approach [Using Sorting]
// Time complexity --> O(nlogn+mlogm) and Space --> O(1)
/*
Where 
    n = length of string s [s.size()]
    m = length of string t [t.size()]
*/
// class Solution
// {
//     public:
//     //Function is to check whether two strings are anagram of each other or not.
//     bool isAnagram(string a, string b){
        
//         // Your code here
//         if(a.size()!=b.size())
//         {
//             return false;
//         }
//         sort(a.begin(),a.end());
//         sort(b.begin(),b.end());

//         return a==b?true:false;
        
//     }

// };

// Optimized Approach [Hash Table]
// Time complexity --> O(n+m) ~ O(n) and Space --> O(1)
/*
Where 
    n = length of string s 
    m = length of string t
*/
// class Solution
// {
//     public:
//     //Function is to check whether two strings are anagram of each other or not.
//     bool isAnagram(string a, string b){
        
//         // Your code here
//         int i, h[26]={0};
//         for(i=0;a[i]!='\0';i++)
//         {
//             h[a[i]-97]++;
//         }
//         for(i=0;b[i]!='\0';i++)
//         {
//             h[b[i]-97]--;
//             if(h[b[i]-97]<0)
//             {
//                 return false;
                
//             }
//         }
//         if(b[i]=='\0')
//         {
//             return true;
//         }
        
//     }

// };

//or

// Time complexity --> O(n) and Space --> O(1)
/*
Where 
    n = length of string s 
    m = length of string t
*/

class Solution
{
    public:
    
     bool allZeroes(vector<int>& count)
    {
        for (int i = 0; i < 26; i++) {
            if(count[i] != 0)
                return false;
        }
        return true;
    }
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        int n = a.length();
        int m = b.length();
        if(n != m)
        {
            return false;
        }  
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[a[i] - 'a']++;
            count[b[i] - 'a']--;
        }
        if(allZeroes(count) == false)
        {
            return false;
        }
            
        return true;
        
        
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