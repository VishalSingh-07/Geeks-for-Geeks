/*
Index of an Extra Element

You have given two sorted arrays arr1[] & arr2[] of distinct elements. The first array has one element extra added in between. Return the index of the extra element.

Note: 0-based indexing is followed.

Example 1:

Input: n = 7, arr1[] = {2,4,6,8,9,10,12}, arr2[] = {2,4,6,8,10,12}
Output: 4
Explanation: In the first array, 9 is extra added and it's index is 4.

Example 2:

Input: n = 6, arr1[] = {3,5,7,8,11,13}, arr2[] = {3,5,7,11,13}
Output: 3
Explanation: In the first array, 8 is extra and it's index is 3.



Expected Time Complexity: O(log n).
Expected Auxiliary Space: O(1).

Constraints:
- 1<=n<=105
- 1<=arr1[i],arr2[i]<=106
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
class Solution {
  bool linearSearch(int n, int arr[], int x){
      for(int i=0;i<n;i++){
          if(arr[i]==x){
              return true;
          }
      }
      return false;
  }
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        
        for(int i=0;i<n;i++){
            if(linearSearch(n,arr2,arr1[i])==false){
                return i;
            }
        }
        return -1;
    }
};

// Above code give time limit exceeded due to high time complexity O(n^2)



// Better Approach
// Time complexity -> O(nlogn) and Space -> O(1)
class Solution {
  bool binarySearch(int n, int arr[], int x){
      int low=0;
      int high=n-1;
      while(low<=high){
          int mid=low+(high-low)/2;
          if(arr[mid]==x){
              return true;
          }
          else if(arr[mid]>x){
              high=mid-1;
          }
          else{
              low=mid+1;
          }
      }
      return false;
  }
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        
        for(int i=0;i<n;i++){
            if(binarySearch(n,arr2,arr1[i])==false){
                return i;
            }
        }
        return -1;
    }
};


// Optimzed Approach
// Time complexity -> O(n) and Space -> O(1)
/*

Since both arrays are given in a sorted manner that means no number 
can not occur twice at any other index.

so we will iterate a loop over the first array elements (i==0; i<n;i++) and 
apply a simple check if arr1[i]!=arr2[i] , then break the loop and 
return the element's position.

and if the element is present at the last position we will check if (i==n) 
then it simply means the extra element is inserted at the last index of the 
first array so return the same index.


*/

class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        
        for(int i=0;i<n;i++){
            if(i==n){
                return i;
            }
            else if(arr1[i]!=arr2[i]){
                return i;
            }
        }
        return -1;
    }
};


// Most Optimized Approach
// Time complexity -> O(logn) and Space -> O(1)

class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low/2);
            // Finding the middle and if they are same means answer will be in our next half of array
            if(arr1[mid]==arr2[mid]){
                low=mid+1;
            }
            // else left half
            else{
                high=mid-1;
            }
        }
        return low;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}
// } Driver Code Ends


// Question link -- https://www.geeksforgeeks.org/problems/index-of-an-extra-element/1