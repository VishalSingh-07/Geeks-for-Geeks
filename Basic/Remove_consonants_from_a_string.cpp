//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Time complexity --> O(n) and Space --> O(1)
class Solution{
    public:
    string removeConsonants(string s){
        //complete the function heredef removeConsonants(s):
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || 
                s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                ans.push_back(s[i]);
            }
        }
        if(ans.size()==NULL)
        {
            return "No Vowel";
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.removeConsonants(s) << "\n";
    }
return 0;
}
// } Driver Code Ends


// Question link -- https://practice.geeksforgeeks.org/problems/c-program-to-remove-consonants-from-a-string1945/1
