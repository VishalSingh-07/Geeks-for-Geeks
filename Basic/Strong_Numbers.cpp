/*
Strong Numbers

Strong Numbers are the numbers whose sum of factorial of digits is equal to the original number. Given a number, the task is to check if it is a Strong Number or not.
 

Example 1:

Input: 145
Output: 1
Explanation: 1! + 4! + 5! = 145
Example 2:

Input: 5314
Output: 0
Explanation: 5! + 3! + 1! + 4! 
is not equal to 5314.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function is_StrongNumber() which takes the number as input parameter and returns 1 if it is Strong Number otherwise returns 0.
 

Expected Time Complexity : O(Number of digits in N)
Expected Space Complexity: O(1)
 

Constraints:
1 <= n <= 10000
*/


//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    int factorial(int number)
    {
        int fact=1;
        for(int i=1;i<=number;i++)
        {
            fact*=i;
        }
        return fact;
    }
	public:
		int is_StrongNumber(int n)
		{
		    // Code here.
		    int temp=n;
		    int sum=0;
		    while(n!=0)
		    {
		        sum=sum+factorial(n%10);
		        n/=10;
		    }
		    return temp==sum?true:false;
		}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_StrongNumber(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends


// Question link -- https://practice.geeksforgeeks.org/problems/strong-numbers4336/1