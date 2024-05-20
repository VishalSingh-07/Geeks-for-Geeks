/*
Modular Exponentiation for large numbers

Implement pow(x, n) % M.
In other words, for a given value of x, n, and M, find  (xn) % M.
 

Example 1:

Input:
x = 3, n = 2, m = 4
Output:
1
Explanation:
32 = 9. 9 % 4 = 1.


Example 2:

Input:
x = 2, n = 6, m = 10
Output:
4
Explanation:
26 = 64. 64 % 10 = 4.

Your Task:
- You don't need to read or print anything. Your task is to complete the function PowMod() which takes integers x, n, and M as input parameters and returns xn % M.
 

Expected Time Complexity: O(log(n))
Expected Space Complexity: O(1)
 
Constraints:
- 1 ≤ x, n, M ≤ 109
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// Optimized Approach
// Time complexity -> O(logn) and Space -> (1)

/*
Note:
    if n is even -> ((x^(n/2))^2) == (x^n)
    if n is odd -> (x.x^(n-1)) == (x^n)
*/
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    long long int ans=1;
		    while(n>0){
		        if(n%2==1){
		            ans=(ans*x)%M;
		            n--;
		        }
		        x=(x*x)%M;
		        n/=2;
		    }
		    return ans;
		}
};




//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1