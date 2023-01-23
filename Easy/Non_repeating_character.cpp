//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Time complexity --> O(n) and Space --> O(n)
class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
      //Your code here
      map<char,int> mp;
      for(int i=0;i<s.length();i++)
      {
          mp[s[i]]++;
      }
      for(int i=0;i<s.length();i++)
      {
          if(mp[s[i]]==1)
          {
              return s[i];
          }
      }
        
        return '$';
      
       
    }

};

// Time complexity --> O(n) and Space --> O(1)
// class Solution
// {
//     public:
//     //Function to find the first non-repeating character in a string.
//     char nonrepeatingCharacter(string s)
//     {
//       //Your code here
//       int arr[26]={0};
//       for(int i=0; i<s.length();i++)
//       {
//           arr[s[i]-'a']++;
//       }
      
//       for(int i=0;i<s.length();i++)
//       {
//           if(arr[s[i]-'a']==1)
//           {
//               return s[i];
//           }
//       }
//       return '$';
      
      
       
//     }

// };


//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/1