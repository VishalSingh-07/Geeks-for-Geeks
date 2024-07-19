/*
Count Smaller elements

Given an array arr containing non-negative integers. Count and return an array ans where ans[i] denotes the number of smaller elements on right side of arr[i].

Examples:

Input: arr[] = [12, 1, 2, 3, 0, 11, 4]
Output: [6, 1, 1, 1, 0, 1, 0]
Explanation: There are 6 smaller elements right after 12. There is 1 smaller element right after 1. And so on.


Input: arr[] = [1, 2, 3, 4, 5]
Output: [0, 0, 0, 0, 0]
Explanation: There are 0 smaller elements right after 1. There are 0 smaller elements right after 2. And so on.



Expected Time Complexity: O(n*logn)
Expected Auxiliary Space: O(n)

Constraints:
- 1 ≤ arr.size() ≤ 10^6
- 0 ≤ arr[i]  ≤ 10^8
*/
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> (n)
class Solution {
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        vector<int> ans;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int count=0;
            int x=arr[i];
            for(int j=i+1;j<n;j++){
                if(x>arr[j]){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

// Above code give Time limit Exceeded due to high complexity O(n^2)


// Optimized Approach
// Time complexity -> O(nlogn) and Space -> (n)
class Solution {
    int binarySearch(vector<int> &temp, int x){
        int index=-1;
        int low=0;
        int high=temp.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(temp[mid]==x){
                index=mid;
                high=mid-1;
            }
            else if(temp[mid]<x){
                low = mid + 1;
            }
            else{
                high=mid-1;
            }
        }
        return index;
    }
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        vector<int> ans;
        int n=arr.size();
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++){
            int index=binarySearch(temp,arr[i]);
            ans.push_back(index);
            
            // Erase the element to ensure it's not found again
            temp.erase(temp.begin()+index);
        }
        return ans;
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
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends


// Question link -- https://www.geeksforgeeks.org/problems/count-smaller-elements2214/1