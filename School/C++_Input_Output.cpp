//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int multiplication(int A, int B){
        // code here 
        return A*B;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.multiplication(A,B) << endl;
    }
    return 0; 
} 

// } Driver Code Ends

// Question Link --- https://practice.geeksforgeeks.org/problems/c-input-output2432/1?page=2&difficulty[]=-2&status[]=solved&sortBy=submissions