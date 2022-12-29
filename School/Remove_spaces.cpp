//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string modify (string s)
    {
        //code here.
        /*
            One Way
            s.erase(remove_if(s.begin(),s.end(),::isspace),s.end());
            return s;
        */
        // Another Way
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                s[i]=NULL;
            }
        }
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore ();
    while (t--)
    {
        string s;
        getline (cin, s);
        Solution ob;
        cout <<ob.modify (s) << endl;
    }
    return 0;
}


// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/remove-spaces0128/1?page=1&difficulty[]=-2&status[]=solved&category[]=Strings&sortBy=submissions