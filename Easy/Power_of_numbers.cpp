/*
Power Of Numbers

Given a number and its reverse. Find that number raised to the power of its own reverse.
Note: As answers can be very large, print the result modulo 109 + 7.

Example 1:

Input:
N = 2
Output: 4
Explanation: The reverse of 2 is 2
and after raising power of 2 by 2 
we get 4 which gives remainder as 
4 by dividing 1000000007.


Example 2:

Input:
N = 12
Output: 864354781
Explanation: The reverse of 12 is 21
and 1221 , when divided by 1000000007 
gives remainder as 864354781.


Your Task:
You don't need to read input or print anything. You just need to complete the function pow() that takes two parameters N and R denoting the input number and its reverse and returns power of (N to R)mod(109 + 7).

Expected Time Complexity: O(LogN).
Expected Auxiliary Space: O(LogN).

Constraints:
1 <= N <= 109
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

// } Driver Code Ends


// Optimized Approach
// Time complexity -> O(logR) and Space -> O(1)

#define mod 1000000007
class Solution{
    public:
    //You need to complete this fucntion
    long long power(int N,int R)
    {
      //Your code here
      long long n=N,r=R;
      long long ans=1;
      while(r!=0)
      {
          if(r%2==0)
          {
                n=(n*n)%mod;
                r=r/2;
          }
          else // if r%2==1
          {
              ans=(ans*n)%mod;
              r=r-1;
          }
      }
      return ans%mod;
       
    }

};




//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}

// } Driver Code Ends


/*
1. Question Link -- https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1

2. Solution Link -- https://leetcode.com/problems/powx-n/solutions/3344673/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/

3. Video Link -- https://youtu.be/l0YC3876qxg
*/
