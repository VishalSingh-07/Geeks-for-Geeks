/*
Rohan's Love for Matrix

Rohan has a special love for the matrices especially for the first element of the matrix. Being good at Mathematics, he also loves to solve the different problem on the matrices. So one day he started to multiply the matrix with the original matrix.  The elements of the original matrix a are given by [a00=1 , a01=1, a10=1, a11=0].

Given the power of the matrix, n calculate the an and return the a10 element mod 1000000007.

Example 1:

Input: 
n = 3
Output: 
2 
Explanation: Take the cube of the original matrix 
i.e a3 and the (a10)th element is 2.




Example 2:

Input: 
n = 4
Output: 
3
Explanation: Take the cube of the original matrix 
i.e a4 and the (a10)th element is 3.


Your Task:  
- You dont need to read input or print anything. Complete the function firstElement() which takes n as input parameter and returns the a10 element mod 1000000007 of an.


Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
- 1<= n <=106
*/


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
  public:
    int firstElement(int n) {
        // code here
        const int mod=1e9+7;
        if(n==0 || n==1){
            return 1;
        }
        int matrix[2][2];
        matrix[0][0]=1;
        matrix[0][1]=1;
        matrix[1][0]=1;
        matrix[1][1]=0;
        
        int a=1,b=1,c=1,d=0;
        int multiply[2][2];
        
        for(int i=2;i<=n;i++){
            multiply[0][0]=(matrix[0][0]*a+matrix[0][1]*c)%mod;
            multiply[0][1]=(matrix[0][0]*b+matrix[0][1]*d)%mod;
            multiply[1][0]=(matrix[1][0]*a+matrix[1][1]*c)%mod;
            multiply[1][1]=(matrix[1][0]*b+matrix[1][1]*d)%mod;
            a=multiply[0][0];
            b=multiply[0][1];
            c=multiply[1][0];
            d=multiply[1][1];
        }
        
        return multiply[1][0]%mod;
    }
};



// Optimized Approach [using Fibonacci Series]
// Time complexity -> O(n) and Space -> O(1)
class Solution {
  public:
    int firstElement(int n) {
        // code here
        const int mod=1e9+7;
        if(n==0 || n==1){
            return 1;
        }
        int a=1,b=1,c=0;
        for(int i=2;i<n;i++){
            c=(a+b)%mod;
            a=b%mod;
            b=c%mod;
        }
        return c%mod;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/rohans-love-for-matrix4723/1