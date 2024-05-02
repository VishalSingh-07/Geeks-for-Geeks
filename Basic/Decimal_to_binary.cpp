/*
Decimal to binary

Given a decimal number N, compute its binary equivalent.

Example 1:

Input: N = 7
Output: 111
 

Example 2:

Input: N = 33
Output: 100001

Your Task:
- You don't need to read input. Complete the function toBinary() which takes the decimal number N as the input parameter and prints its binary equivalent.

Note: Print the output in a single line, the next line character is printed by the Driver Code.
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

void toBinary(int n)
{
    // your code here
    string binary="";
    while(n>0){
        binary=to_string(n%2)+binary;
        n/=2;
    }
    cout<<binary;
        
}

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
	cin>>t;
	
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    toBinary(n);
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/decimal-to-binary-1587115620/1