/*
Number of Subarrays of 0's

You are given an array arr  of length N of 0's and 1's. Find the total number of subarrays of 0's

Example 1:

Input:
N = 4
arr[] = {0, 0, 1, 0}
Output:
4

Explanation:
Following are the subarrays of
length 1: {0}, {0}, {0} - 3
length 2: {0, 0} - 1
Total Subarrays: 3 + 1 = 4



Example 2:

Input:
N = 4
arr[] = {0, 0, 0, 0}
Output:
10
Explanation:
Following are the subarrays of
length 1: {0}, {0}, {0}, {0} - 4
length 2: {0, 0}, {0, 0}, {0, 0} - 3
length 3: {0, 0, 0}, {0, 0, 0} - 2
length 4: {0, 0, 0, 0} - 1
Total Subarrays: 4 + 3 + 2 + 1 = 10


Your Task:

Your task is to complete the function no_of_subarrays(), which takes an integer N and an integer array arr as the input parameters and returns an integer denoting the total number of subarrays of 0's.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:

1 <= N <= 106
0 <= arr[i] <= 1
View Bookmarked Problems 

*/

/*
Explanation:
Count the Number of Subarrays of Zeros in a Binary Array !!

Approach : 
To solve this problem, we can traverse the given array arr and 
keep track of the number of zeros we have encountered so far. 
When we encounter a 1, we can calculate the number of subarrays 
of 0's that can be formed using the number of zeros we have 
encountered so far and add it to our count.


Algorithm:

 

1. Initialize two variables count and zeros to 0.
2. Traverse the array arr from left to right.
3. If the current element is 0, increment the zeros variable by 1.
4. If the current element is 1, calculate the number of subarrays of 0's that can be formed using the zeros variable and add it to the count variable. Reset the zeros variable to 0.
5. After we have traversed the entire array, calculate the number of subarrays of 0's that end at the last index separately using the zeros variable and add it to the count variable.
6. Return the total count of subarrays of 0's.
 



Time Complexity :  

The time complexity of the given solution is O(N), where N is the length of the input array arr.

This is because we are traversing the array arr only once in a linear manner, and performing a constant amount of operations for each element.

Thus, the time complexity of the given solution is linear in the size of the input array, and hence it is an efficient solution.
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    long long count=0; // Initialize count of subarrays of 0's to 0
    long long zeros=0; // Initialize count of zeros to 0
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            zeros++; // Increment count of zeros encountered so far
        }
        if(arr[i]==1)
        {
            count+=(zeros+1)*(zeros)/2; // add it to the overall count
            zeros=0; // Reset the count of zeros encountered so far
        }
    }
    count+=(zeros+1)*(zeros)/2; // Add the count of subarrays of 0's that end at the last index separately
    
    return count; // Return the total count of subarrays of 0's 
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/0960a833f70b09c59444ea487f99729929fc8910/1