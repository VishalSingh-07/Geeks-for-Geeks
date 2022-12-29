//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void printTillN(int N)
    {
        // Write Your Code here
        if(N>=1)
        {
            printTillN(N-1);
            cout<<N<<" ";
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        ob.printTillN(N);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/print-1-to-n-without-using-loops3621/1?page=2&difficulty[]=-2&status[]=solved&sortBy=submissions