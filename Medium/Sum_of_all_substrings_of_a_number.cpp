//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(n)
// class Solution
// {
//     public:
//     //Function to find sum of all possible substrings of the given string.
//     long long sumSubstrings(string s){
//         // your code here
//         long long ans=0;
//         int modulo=1e9+7;
//         for(int i=0;i<s.length();i++){
//             string substr="";
//             for(int j=i;j<s.length();j++){
//                 substr+=s[j];
//                 ans+=(stoll(substr))%modulo;
//             }
//         }
//         return ans;
//     }
// };

// Above code not working

// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        // your code here
        int mod=1e9+7;
        int n=s.size();
        vector<long long> dp(n,0);
        dp[0]=s[0]-'0';
        long long ans=dp[0];
        for(int i=1;i<n;i++){
            dp[i]=((dp[i-1]*10)%mod+ ((s[i]-'0')*(i+1))%mod)%mod;
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1

// Solution link -- https://drive.google.com/file/d/1SFydzHpxXuovQOXd8TO1amvVaf4KAOPC/view?usp=sharing