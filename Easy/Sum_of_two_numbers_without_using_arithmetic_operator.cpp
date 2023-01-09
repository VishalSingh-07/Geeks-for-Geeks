//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

// Time Complexity --> O(n) and space --> O(1)
// class Solution
// {
//     public:
//     int sum(int a , int b)
//     {
//         //code here
//         for(int i=0;i<b;i++)
//         {
//             a++;
            
//         }
//         return a;
//     }
// };

// Above code is not working due to time limit exceeded

// Time complexity --> O(max(number of bits in 'a' ,number of bits in 'b')) and Space --> O(1)
class Solution
{
    public:
    int sum(int a , int b)
    {
        //code here
        int sum,carry=b;
        while(carry!=0)
        {
            sum=a^b;
            carry=(a&b)<<1;
            
            a=sum;
            b=carry;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a>>b;
        
        Solution ob;
        cout<< ob.sum(a,b) <<"\n";
        
    }
    return 0;
}

// } Driver Code Ends


// Question link --> https://practice.geeksforgeeks.org/problems/sum-of-two-numbers-without-using-arithmetic-operators/1