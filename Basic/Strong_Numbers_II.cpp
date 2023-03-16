/*
Strong Numbers

Strong Numbers are the numbers whose sum of factorial of digits is equal to the original number. Given a number N, the task is to check if it is a Strong Number or not. Print 1 if the Number is Strong, else Print 0.

 

Example 1:

Input:
N = 145
Output:
1
Explanation:
1! + 4! + 5! = 145 So, 145 is a Strong
Number and therefore the Output 1.
Example 2:

Input:
N = 14
Output:
0
Explanation:
1! + 4! = 25 So, 14 isn't a Strong
Number and therefore the Output "NO".
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function isStrong() which takes an Integer N as input and returns the answer.

 

Expected Time Complexity: O(|N|)
Expected Auxiliary Space: O(1)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
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
    int isStrong(int n) {
        // code here
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
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.isStrong(N) << endl;
    }
    return 0;
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/strong-numbers3315/1