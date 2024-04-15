/*
Count the elements

Given two arrays a and b both of size n. Given q queries in an arrray query each having a positive integer x denoting an index of the array a. For each query, your task is to find all the elements less than or equal to a[x] in the array b.

Example 1:

Input:
n = 3
a[] = {4,1,2}
b[] = {1,7,3}
q = 2
query[] = {0,1}
Output : 
2
1
Explanation: 
For 1st query, the given index is 0, a[0] = 4. There are 2 elements(1 and 3) which are less than or equal to 4.
For 2nd query, the given index is 1, a[1] = 1. There exists only 1 element(1) which is less than or equal to 1.


Example 2:

Input:
n = 4
a[] = {1,1,5,5}
b[] = {0,1,2,3}
q = 4
query[] = {0,1,2,3}
Output : 
2
2
4
4

Explanation: 
For 1st query and 2nd query, the given index is 0 and 1 respectively, a[0] = a[1] = 1. There are 2 elements(0 and 1) which are less than or equal to 1. 
For 3rd query and 4th query, the given index is 2 and 3 respectively, a[2] = a[3] = 5. All the 4 elements are less than or equal to 5.   

Your Task:
- You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function countElements() that takes array a and b of size n, and array query of size q as parameters and returns an array that contains the answer to the corresponding queries. 

Expected Time Complexity: O(n+q+maximum of a and b).
Expected Auxiliary Space: O(maximum of a and b).

Constraints:
- 1 ≤ q ≤ n ≤ 105
- 1 ≤ a[i], b[i] ≤ 105
- 0 ≤ query[i] < n
*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Brute Force Approach
// Time complexity -> O(q*n) and Space -> O(1)
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        vector<int> ans;
        for(int i=0;i<q;i++){
            int x=a[query[i]];
            int count=0;
            for(int j=0;j<n;j++){
                if(b[j]<=x){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

// Above code give Time Limit Exceeded due to high complexity O(n*q)

// Better Approach
// Time complexity -> O(nlogn + qlogn) and Space -> O(1)
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        sort(b.begin(),b.end());
        vector<int> ans;
        for(int i=0;i<q;i++){
            int count=upper_bound(b.begin(),b.end(), a[query[i]]) - b.begin();
            ans.push_back(count);
        }
        return ans;
        
    }
};



// Optimized Approach
// Time complexity -> O(max(maxi,n,q)) and Space -> O(maxi)
// where maxi: maximum element in array b
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
                                  
        // Initialize a variable to find the maximum element in array b
        int maxi=0;
        
        // Finding the maximum Element in array b
        for(int i=0;i<n;i++){
            maxi=max(maxi,b[i]);
        }
        
        // Create a vector to store the frequency of each element in array b
        vector<int> freq(maxi+1,0);
        
        
        // Calculate the frequency of each element in array b
        for(int i=0;i<n;i++){
            freq[b[i]]++;
        }
        
        // Perform cumulative sum on the frequency array
        for(int i=1;i<=maxi;i++){
            freq[i]+=freq[i-1];
        }
        
        // Create a vector to store the counts for each query
        vector<int> ans;
        
        // Iterate through the queries
        for(int i=0;i<q;i++){
            int x=query[i];
            
            // If the element in array a is greater than the maximum element in array b,
            // push the size of array b into the answer vector,
            // otherwise, push the frequency of a[x] from the freq array.
            if(a[x]>maxi){
                ans.push_back(n);   
            }
            else{
                ans.push_back(freq[a[x]]);
            }
        }
        return ans;
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends

/*
1. Question link -- https://www.geeksforgeeks.org/problems/count-the-elements1529/1

2. Solution link -- https://youtu.be/a3fgbC50pxQ?feature=shared
*/