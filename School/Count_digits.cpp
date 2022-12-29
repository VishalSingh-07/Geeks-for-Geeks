//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        //code here
        int temp=N; // storing the value of N
        int count=0; // initialize the count with 0
        while(temp>0) 
        {
            int digit=temp%10;
            if(digit!=0 && N%digit==0)
            {
                count++;
                
            }
            temp=temp/10;
            
            
        }
        return count;
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
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends

// Question Link --- https://practice.geeksforgeeks.org/problems/count-digits5716/1?page=2&difficulty[]=-2&status[]=solved&sortBy=submissions