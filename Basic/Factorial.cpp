//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int factorial(int N){
        //code here
        if(N==0)
        {
            return 1;
        }
        else
        {
            return factorial(N-1)*N;
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
        cin>>N;
        Solution ob;
        cout << ob.factorial(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/factorial5739/1?page=1&difficulty[]=-1&status[]=solved&sortBy=submissions