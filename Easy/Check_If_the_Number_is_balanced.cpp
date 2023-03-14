/*
Check if the number is balanced

Given an integer N which has odd number of digits, find whether the given number is a balanced or not.

An odd digit number is called a balanced number if the sum of all digits to the left of the middle digit and the sum of all digits to the right of the middle digit is equal.

Example 1:

Input:
N = 1234006
Output: 1 
Explanation: Total number of digits in
N = 7. Middle digit is 4. LHS = 1+2+3 = 6
and RHS = 0+0+6 = 6. LHS is equal to RHS. 

Example 2:

Input:
N = 12345
Output: 0
Explanation: LHS = 1+2 = 3 and RHS = 4+5
= 9. LHS and RHS are not equal.

Your Task:  
You dont need to read input or print anything. Complete the function balancedNumber() which takes string N as input parameter and returns a boolean value denoting if N is balanced or not.
Note: The driver code prints 1 if the returned value is true otherwise 0


Expected Time Complexity: O(number of digits in N)
Expected Auxiliary Space: O(1)


Constraints:
1<= N <= 10100
N will always have odd number of digits.
Since N can be very large, it is given as a string. 
 
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution{
public:	
	bool balancedNumber(string N)
	{
	    // code here
        int n=N.size();
	    int sum_left=0,sum_right=0;
	    for(int i=0;i<n/2;i++)
	    {
	        sum_left+=(N[i]-'0');
	    }
	    for(int i=n/2+1;i<n;i++)
	    {
	        sum_right+=(N[i]-'0');
	    }
	    if(sum_left==sum_right)
	    {
	        return true;
	    }
	    return false;
	    
	}
};

// OR



class Solution{
public:	
	bool balancedNumber(string N)
	{
	    // code here
        int n=N.size();
	    int sum_left=0,sum_right=0;
	    for(int i=0;i<n/2;i++)
	    {
	        sum_left+=(N[i]-'0');
	        sum_right+=(N[n-1-i]-'0');
	    }
	    if(sum_left==sum_right)
	    {
	        return true;
	    }
	    return false;
	    
	}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string N;
        cin>>N;
        Solution ob;
        cout<<ob.balancedNumber(N)<<endl;
    }
    return 0;
}

// } Driver Code Ends


// Question link --https://practice.geeksforgeeks.org/problems/check-if-the-number-is-balanced3014/1