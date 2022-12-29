//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User functiom template for C++

class Solution {
  public:
    int BasicDataType(string s) {
        // code here
        int size=s.length();
        if(size==1)
        {
            if(s[0]>='0' && s[0]<='9') // Checking whether is string int or not
            {
                return sizeof(int);
            }
            else // Returning sizeof(char) when the length of the string
            {
                return sizeof(char);
            }
        }
        
        for(int i=0;i<size;i++)
        {
            if(s[i]=='.') // checking whether in a string dot(.) is contain or not because to find whether string double or float
            {
                if((size-1-i)>=6) // checking number of digit after point if it is greater than 6 then double else float
                {
                    return sizeof(double); // returning size of char
                }
                else
                {
                    return sizeof(float); // returning size of float
                }
            }
        }
        return sizeof(int); // nothing satisfies return int
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.BasicDataType(S) << endl;
    }
}
// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/c-basic-data-types3128/1?page=1&difficulty[]=-1&status[]=solved&category[]=Strings&sortBy=submissions