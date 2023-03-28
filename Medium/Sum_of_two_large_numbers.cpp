/*
Sum of two large numbers

Given two strings denoting non-negative numbers X and Y. Calculate the sum of X and Y.


Example 1:

Input:
X = "25", Y = "23"
Output:
48
Explanation:
The sum of 25 and 23 is 48.


Example 2:

Input:
X = "2500", Y = "23"
Output:
2523


Explanation:
The sum of 2500 and 23 is 2523.

Your Task:
Your task is to complete the function findSum() which takes two strings as inputs and returns the string without leading zeros. You do not need to take any input or print anything.


Expected Time Complexity: O(|X| + |Y|)
Expected Auxiliary Space: O(1)


Constraints:
1 <= |X|, |Y| <= 105
*/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


// class Solution {
//   public:
//     string findSum(string X, string Y) {
//         // Your code goes here
//         int x=stoi(X);
//         int y=stoi(Y);
        
//         int sum=x+y;
        
//         return to_string(sum);
//     }
// };

// Optimized Approach
// Time complexity -> O(max(n,m)) and Space -> O(1)
// Where n =  length of string X and m = length of string Y

class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        int i=X.size()-1,j=Y.size()-1;
        int sum=0,carry=0;
        string ans="";
        
        // For String X and Y
        while(i>=0 && j>=0)
        {
            sum=X[i]-'0'+Y[j]-'0';
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            ans+=to_string(sum);
            i--;
            j--;
        }
        // for string X if Y is shorter
        while(i>=0)
        {
            sum=X[i]-'0';
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            ans+=to_string(sum);
            i--;
        }
        // For string Y if X is shorter
        while(j>=0)
        {
            sum=Y[j]-'0';
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            ans+=to_string(sum);
            j--;
        }
        if(carry!=0)
        {
            ans+=to_string(carry);
        }
        
        int k=ans.size()-1;
        
        // ending zero delete
        while(k>=1 && ans[k]=='0')
        {
            ans.pop_back();
            k--;
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/sum-of-numbers-or-number1219/1