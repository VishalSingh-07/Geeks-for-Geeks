/*
Sum of Products

Given an array arr[] of size n. Calculate the sum of Bitwise ANDs ie: calculate sum of arr[i] & arr[j] for all the pairs in the given array arr[] where i < j.

Example 1:

Input:
n = 3
arr = {5, 10, 15}
Output:
15
Explanation:
The bitwise Ands of all pairs where i<j are (5&10) = 0, (5&15) = 5 and (10&15) = 10.
Therefore, the total sum = (0+5+10) = 15.


Example 2:

Input:
n = 4
arr = {10, 20, 30, 40}
Output:
46
Explanation:
The sum of bitwise Ands 
of all pairs = (0+10+8+20+0+8) = 46.


Your Task:
- You don't need to read input or print anything.Your Task is to complete the function pairAndSum() which takes an Integer n and an array arr[]  of size n as input parameters and returns the sum of bitwise Ands of all pairs.

Expected Time Complexity:O(n)
Expected Auxillary Space:O(1)

Constraints:
1 <= n <= 105
1 <= arr[i] <= 108
*/
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// Brute Force Approach
// Time complexity-> O(n^2) and Space -> O(1)
class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        long long sum=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                sum+=arr[i]&arr[j];
            }
        }
        return sum;
    }
};

// Above code give time limit exceeded due to high compleixty O(n^2)

// Optimized Approach
// Time complexity -> O(n*32) and Space -> O(32)
class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        vector<int> bits(32,0);
        for(int i=0;i<n;i++){
            int temp=arr[i];
            int j=0;
            while(temp){
                if(temp&1){
                    bits[j]++;
                }
                j++;
                temp>>=1;
            }
        }
        long long sum=0;
        for(int i=0;i<32;i++){
            long long temp=bits[i];
            temp--;
            long long pairs=(temp*(temp+1))/2;
            sum+=(pairs*(long long)pow(2,i));
        }
        return sum;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
/*
1. Question link -- https://www.geeksforgeeks.org/problems/sum-of-products5049/1

2. Video Link -- https://youtu.be/8uAFlooi-p4?feature=shared
*/