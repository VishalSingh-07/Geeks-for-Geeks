/*
Implement Atoi

Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.

Note: You are not allowed to use inbuilt function.

Example 1:

Input:
str = 123
Output: 123


Example 2:

Input:
str = 21a
Output: -1
Explanation: Output is -1 as all
characters are not digit only.


Your Task:
Complete the function atoi() which takes a string as input parameter and returns integer value of it. if the input string is not a numerical string then returns -1.
Note: Numerical strings are the string where either every character is in between 0-9 or where the first character is '-' and the rest all characters are in between 0-9.

Expected Time Complexity: O(|S|), |S| = length of string str.
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ length of S ≤ 10


Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/



//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

// class Solution{
//   public:
//     /*You are required to complete this method */
//     int atoi(string str) {
//         //Your code here
//         int x=stoi(str);
//         return x;
//     }
// };


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
// where n = length of string str
// class Solution{
//   public:
//     /*You are required to complete this method */
//     int atoi(string str) {
//         //Your code here
        
//         int ans;
//         int n=str.size();
//         bool flag=false;
//         if(str[0]=='-')
//         {
//             flag=true;
//         }
//         if(flag)
//         {
//             for(int i=1;i<n;i++)
//             {
//                 char ch=str[i];
//                 if(isdigit(ch))
//                 {
//                     /*
//                     Iterate through all characters of input string and update
//                     result take ASCII character of corresponding digit and subtract
//                     from '0' to get numerical value and multiply ans by 10 to shuffle 
//                     digits left to update running total
//                     */
//                     ans=ans*10+(ch-'0');
//                 }
//                 else
//                 {
//                     return -1;
//                 }
//             }
//         }
//         else
//         {
//             for(int i=0;i<n;i++)
//             {
//                 char ch=str[i];
//                 if(isdigit(ch))
//                 {
//                     /*
//                     Iterate through all characters of input string and 
//                     update result take ASCII character of corresponding 
//                     digit and subtract from '0' to get numerical value 
//                     and multiply ans by 10 to shuffle digits left to 
//                     update running total.
//                     */
//                     ans=ans*10+(ch-'0');
//                 }
//                 else
//                 {
//                     return -1;
//                 }
//             } 
//         }
        
//         if(flag)
//         {
//             return ans*-1;
//         }
        
//         return ans;
//     }
// };

// OR ---------
class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        
        int ans;
        int n=str.size();
        bool flag=false;
        int i=0;
        if(str[0]=='-')
        {
            flag=true;
            i=1;
        }
        for(;i<n;i++)
        {
            char ch=str[i];
            if(isdigit(ch))
            {
                /*
                Iterate through all characters of input string and 
                update result take ASCII character of corresponding 
                digit and subtract from '0' to get numerical value 
                and multiply ans by 10 to shuffle digits left to 
                update running total.
                */
                ans=ans*10+(ch-'0');
            }
            else
            {
                return -1;
            }
        }
        
        if(flag)
        {
            ans*=-1;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/implement-atoi/1