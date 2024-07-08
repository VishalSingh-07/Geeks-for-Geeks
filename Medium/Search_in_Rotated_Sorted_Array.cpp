/*
Search in Rotated Sorted Array

Given a sorted (in ascending order) and rotated array arr of distinct elements which may be rotated at some point and given an element key, the task is to find the index of the given element key in the array arr. The whole array arr is given as the range to search.

Rotation shifts elements of the array by a certain number of positions, with elements that fall off one end reappearing at the other end.

Note:- 0-based indexing is followed & returns -1 if the key is not present.

Examples :

Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 10
Output: 5
Explanation: 10 is found at index 5.

Input: arr[] = [3, 5, 1, 2], key = 6
Output: -1
Explanation: There is no element that has value 6.
Expected Time Complexity: O(log n)
Expected Auxiliary Space: O(1)

Constraints:
- 1 ≤ arr.size() ≤ 106
- 0 ≤ arr[i] ≤ 106
- 1 ≤ key ≤ 105
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        for(int i=0;i<arr.size();i++){
            if(arr[i]==key){
                return i;
            }
        }
        return -1;
    }
};


// Optimized Approach
// Time complexity -> O(logn) and Space -> O(1)
/*
1. Check Key Presence: If the key is not in the array, return -1.

2. Initialize Pointers: Set low to the start (0) and high to the end (length of the array - 1).

3. Binary Search Loop: Continue the loop while low is less than or equal to high.

4. Calculate Midpoint: Compute the middle index mid.

5. Check Midpoint: If the element at mid equals the key, return mid.

6. Determine Sorted Half:
    - If the left half is sorted (arr[low] <= arr[mid]):
        - If the key lies in this sorted half (arr[left] <= key  &&  key < arr[mid]), search in this half by setting high = mid - 1.
        - Otherwise, search in the right half by setting low = mid + 1.
    - If the right half is sorted:
        - If the key lies in this sorted half (arr[mid] < key  && key<= arr[right]), search in this half by setting low = mid + 1.
        - Otherwise, search in the left half by setting highq = mid - 1.
*/
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==key){
                return mid;
            }
            
            // checking left half sorted array
            else if(arr[low]<=arr[mid]){
                if(arr[low]<=key && key<arr[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            // checking right half sorted array
            else{
                if(arr[mid]<key && key<=arr[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};






//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*
1. Question link -- https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1

2. Video link -- https://youtu.be/NfxFcA5knVU?feature=shared
*/