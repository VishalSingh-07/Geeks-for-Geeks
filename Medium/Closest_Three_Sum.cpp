/*
Closest Three Sum

Given an array, arr of integers, and another number target, find three integers in the array such that their sum is closest to the target. Return the sum of the three integers.

Note: If there are multiple solutions, return the maximum one.

Examples :

Input: arr[] = [-7, 9, 8, 3, 1, 1], target = 2
Output: 2
Explanation: There is only one triplet present in the array where elements are -7,8,1 whose sum is 2.


Input: arr[] = [5, 2, 7, 5], target = 13
Output: 14
Explanation: There is one triplet with sum 12 and other with sum 14 in the array. Triplet elements are 5, 2, 5 and 2, 7, 5 respectively. Since abs(13-12) ==abs(13-14) maximum triplet sum will be preferred i.e 14.


Expected Time Complexity: O(n^2)
Expected Auxiliary Space: O(1)

Constraints:
- 3 ≤ arr.size() ≤ 10^3
- -105 ≤ arr[i] ≤ 10^5
- 1 ≤ target ≤ 10^5
*/

/*
Hint 1 - Sort the given array to improve the efficiency of the algorithm.

Hint 2 - Fix one element in the sorted array, and use the two pointer technique to find the remaining integers. 
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

// Optimized Approach
// Time complexity ->O(nlogn + n^2) ~ O(n^2) and Space -> O(!)
class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int closestSum=INT_MAX;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int left=i+1,right=n-1;
            while(left<right){
                int currentSum=arr[i]+arr[left]+arr[right];
                if(abs(currentSum-target)<abs(closestSum-target)){
                    closestSum=currentSum;
                }
                else if(abs(currentSum-target)==abs(closestSum-target)){
                    closestSum=max(closestSum,currentSum);
                }
                
                if(currentSum<target){
                    left++;
                }
                else{
                    right--;
                }
            }
            
        }
        return closestSum;
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
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/three-sum-closest/1