//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string oddEven(int N){
        // code here 
        if(N%2==0)
        {
            cout<<"even";
        }
        else
        {
            cout<<"odd";
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.oddEven(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/odd-or-even3618/1?page=2&difficulty[]=-2&status[]=solved&sortBy=submissions