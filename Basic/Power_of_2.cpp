//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


// Brute Force Approach
// Time complexity: O(n) and Space --> O(1)
class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here 
        for(int i=0;i<n;i++)
        {
            long long x=pow(2,i);
            if(x==n)
            {
                return true;
            }
        }
        return false;
        
    }
};

// Above code give Time limit exceeded due to O(n) time complexity

// Counting Set bit [Brian Kernighan’s Algorithm]
// Time complexity --> O(logn) and Space --> O(1)
class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here 
        int count=0;
        if(n<=0)
        {
            return false;
        }
        while(n)
        {
            count+=n&1;
            n>>=1;
        }
        if(count==1)
        {
            return true; // // any number which is power of 2 have exactly one set bit
        }
        return false;
        
    }
};


// Counting Set bit [Using STL C++ Function]
// Time complexity --> O(logn) and Space --> O(1)
class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here 
        if(n==0)
        {
            return false;
        }
        int count= __builtin_popcountll(n);
        if(count==1)
        {
            return true; // // any number which is power of 2 have exactly one set bit
        }
        return false;
        
    }
};


//Bit Shift Approach
// Time complexity --> O(logn) and Space --> O(1)
class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here 
        if(n==0)
        {
            return false;
        }
        while(n>1 && (n&1)==0)
        {
            n>>=1;
        }
        
        return n==1?true:false;
        
    }
};


//Bit Trick Approach
// Time complexity --> O(1) and Space --> O(1)
class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here 
        if(n<=0)
        {
            return false;
        }
        
        return ((n&(n-1))==0)?true:false;
        
    }
};


//Optimized Approach [Using Floor and Ceil]
// Time complexity --> O(1) and Space --> O(1)
class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here 
        if(n==0)
        {
            return false;
        }
        return floor(log2(n))==ceil(log2(n))?true:false;
        
    }
};






//{ Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}

// } Driver Code Ends


// Question link -- https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1


// My solution link -- https://leetcode.com/problems/power-of-two/solutions/3147224/7-approach-to-solve-a-problem-brute-force-count-set-bits-bit-shift-bit-trick-optimized/

// Video link -- https://youtu.be/4cqHahxFTYw