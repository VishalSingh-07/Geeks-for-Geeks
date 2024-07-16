/*
Remaining String

Given a string s without spaces, a character ch and an integer count. Your task is to return the substring that remains after the character ch has appeared count number of times.


Note:  Assume upper case and lower case alphabets are different. “”(Empty string) should be returned if it is not possible, or the remaining substring is empty.

Examples:

Input: s = "Thisisdemostring", ch = 'i', count = 3
Output: ng
Explanation: The remaining substring of s after the 3rd
occurrence of 'i' is "ng", hence the output is ng.



Input: s = "Thisisdemostri", ch = 'i', count = 3
Output: ""
Explanation: The 3rd occurence of 'i' is at the last index. In this case the remaining substring is empty, hence we return empty string.



Input: s = "abcd", ch = 'x', count = 2
Output: ""
Explanation: The character x is not present in the string, hence we return empty string.



Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(1)

Constraints:
- 1<= s.length()<=10^5
- 1<=count<=s.length()
- s[i] is both upper case and lower case
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
// where n: Length of the string s

// User function template for C++
class Solution {
  public:
    string printString(string s, char ch, int count) {
        // Your code goes here
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==ch){
                count--;
            }
            if(count==0){
                if(i+1<n){
                  ans=s.substr(i+1);
                }else{
                    ans="";
                }
                break;
            }
        }
        return ans;
    }
};



// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
// where n: Length of the string s

// User function template for C++
class Solution {
  public:
    string printString(string s, char ch, int count) {
        // Your code goes here
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==ch){
                count--;
            }
            if(count==0){
                if(i+1<n){
                  return s.substr(i+1);
                }
            }
        }
        return "";
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
        string s;
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends


// Question link -- https://www.geeksforgeeks.org/problems/remaining-string3515/1