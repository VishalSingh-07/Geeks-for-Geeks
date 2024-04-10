/*
Party of Couples

You are given an integer array arr[] of size n, representing n number of people in a party, each person is denoted by an integer. Couples are represented by the same number ie: two people have the same integer value, it means they are a couple. Find out the only single person in the party of couples.

NOTE: It is guarantee that there exist only one single person in the party.

Example 1:

Input: 
n = 5
arr = {1, 2, 3, 2, 1}
Output: 
3
Explaination: Only the number 3 is single.
Example 2:

Input: 
n = 11 
arr = {1, 2, 3, 5, 3, 2, 1, 4, 5, 6, 6} 
Output: 
4 
Explaination: 4 is the only single.
Your Task:
You do not need to read input or print anything. Your task is to complete the function findSingle() which takes the size of the array n and the array arr[] as input parameters and returns the only single person.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 104
1 ≤ arr[i] ≤ 106


*/
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution{
    public:
    int findSingle(int n, int arr[]){
        // code here
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        for(auto x: mpp){
            if(x.second%2!=0){
                return x.first;
            }
        }
        return -1;
    }
};

// Above code give Time Limit Exceeded due to Time Complexity O(n) and Space -> O(n)


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution{
    public:
    int findSingle(int n, int arr[]){
        // code here
        int Xor=0;
        for(int i=0;i<n;i++){
            Xor^=arr[i];
        }
        return Xor;
    }
};







//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.findSingle(N, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/alone-in-couple5507/1