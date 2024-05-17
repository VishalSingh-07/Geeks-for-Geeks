/*
Find Pair Given Difference

Given an array arr[] of size n and an integer x, return 1 if there exists a pair of elements in the array whose absolute difference is x, otherwise, return -1.

Example 1:

Input:
n = 6
x = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output:
1
Explanation:
Pair (2, 80) have absolute difference of 78.


Example 2:

Input:
n = 5
x = 45
arr[] = {90, 70, 20, 80, 50}
Output:
-1
Explanation:
There is no pair with absolute difference of 45.


Your Task:
- You need not take input or print anything. Your task is to complete the function findPair() which takes integers n, x, and an array arr[] as input parameters and returns 1 if the required pair exists, return -1 otherwise.

Expected Time Complexity: O(n* Log(n)).
Expected Auxiliary Space: O(1).

Constraints:
- 1<=n<=106 
- 1<=arr[i]<=106 
- 0<=x<=105
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(arr[i]-arr[j])==x){
                    return 1;
                }
            }
        }
        return -1;
    }
};

// Above code give timit limit exceeded due to high time complexity O(n^2)


// Better Approach
// Time complexity -> O(nlogn) and Space -> O(1)
class Solution {
    bool binarySearch(vector<int> &arr, int n, int x, int pos){
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==x && mid!=pos){
                return true;
            }
            else if(arr[mid]<x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
  public:
    int findPair(int n, int x, vector<int> &arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int find=arr[i]+x;
            if(binarySearch(arr,n,find,i)==true){
                return 1;
            }
        }
        return -1;
    }
};


// Optimized Approach 
// Time complexity -> O(n) and Space -> O(n)
class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
            if(x==0 && mpp[arr[i]]==2){
                return 1;
            }
            
        }
        if(x==0){
            return -1;
        }
        for(auto it: mpp){
            if(mpp.find(x+it.first)!=mpp.end()){
                    return 1;
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1