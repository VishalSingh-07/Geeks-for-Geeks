/*
Segregate 0s and 1s

Given an array arr consisting of only 0's and 1's in random order. Modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.

Examples :

Input: arr[] = [0, 0, 1, 1, 0]
Output: [0, 0, 0, 1, 1]
Explanation:  After segregation, all the 0's are on the left and 1's are on the right. Modified array will be [0, 0, 0, 1, 1].



Input: arr[] = [1, 1, 1, 1]
Output: [1, 1, 1, 1]
Explanation: There are no 0s in the given array, so the modified array is [1, 1, 1, 1]



Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
- 1 ≤ arr.size() ≤ 10^6
- 0 ≤ arr[i] ≤ 1
*/
//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// Brute Force Approach [Sorting]
// Time complexity -> O(nlogn) and Space -> O(1)
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
    }
};


// Optimized Approach [Two Pointer]
// Time complexity -> O(n) and Space -> O(1)
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int left=0;
        int right=arr.size()-1;
        while(left<right){
            if(arr[left]==1 && arr[right]==0){
                swap(arr[left],arr[right]);
                left++;
                right--;
            }
            else if(arr[left]==0){
                left++;
            }
            else if(arr[right]==1){
                right--;
            }
        }
    }
};


// OR

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int left=0;
        int right=arr.size()-1;
        while(left<right){
            while(arr[left]==0 && left<right){
                left++;
            }
            while(arr[right]==1 && left<right){
                right--;
            }
            if(left<right){
                swap(arr[left],arr[right]);
                left++;
                right--;
            }
        }
    }
};





//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        ob.segregate0and1(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1