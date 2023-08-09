//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int n){
        // code here
        long long int maxi=INT_MIN;
        while(n%2==0)
        {
            maxi=max(maxi,(long long int)2);
            n/=2;
        }
        // traversing through odd numbers
        for(int i=3;i<=sqrt(n);i+=2)
        {
            while(n%i==0)
            {
                maxi=max(maxi,(long long int)i);
                n/=i;
            }
        }
        // if n is itself a prime number than we update the ans
        if(n>2)
        {
            maxi=max(maxi,(long long int)n);
        }
        return maxi;
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
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/largest-prime-factor2601/1