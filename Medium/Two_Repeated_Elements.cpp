/*
Two Repeated Elements

You are given an integer n and an integer array arr of size n+2. All elements of the array are in the range from 1 to n. Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.

Note: Return the numbers in their order of appearing twice. So, if X and Y are the repeating numbers, and X's second appearance comes before second appearance of Y, then the order should be (X, Y).

Example 1:
Input:
n = 4
arr[] = {1,2,1,3,4,3}
Output: 
1 3
Explanation: 
In the given array, 1 and 3 are repeated two times and as 1's second appearance occurs before 2's second appearance, so the output should be 1 3.


Example 2:
Input:
n = 2
arr[] = {1,2,2,1}
Output: 
2 1


Explanation: 
- In the given array, 1 and 2 are repeated two times and second occurence of 2 comes before 1. So the output is 2 1.

Your Task:
- The task is to complete the function repeatedElements() which takes an integer array arr[] and an integer n as inputs (the size of the array is n + 2 and elements are in the range [1, n]) and finds the two repeated elements in the array and return them in an array.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1). 

Constraints:
- 2 ≤ n ≤ 105
- 1 ≤ arr[i] ≤ n
*/


//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // Your code here
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0;i<n+2;i++){
            if(mpp.find(arr[i])!=mpp.end()){
                ans.push_back(arr[i]);
            }else{
                mpp[arr[i]]++;
            }
        }
        return ans;
    }
};

// OR

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // Your code here
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0;i<n+2;i++){
            mpp[arr[i]]++;
            if(mpp[arr[i]]==2){
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};


/*
Approach:
1. Iterate through the array: The code iterates through each element of the array, 
checking if the element is negative or positive.

2. Utilize the given range of numbers: Since all elements of the array are in the 
range from 1 to n and each number appears twice (with two numbers appearing twice), 
the algorithm can use the array itself as a way to mark visited elements.

3. Find repeated elements: For each element arr[i], the algorithm checks the element 
at the index abs(arr[i]):
- If the element at that index (arr[abs(arr[i])]) is negative, it means abs(arr[i]) 
has been encountered before. Hence, the algorithm adds abs(arr[i]) to the result (ans).

- If the element at the index (arr[abs(arr[i])]) is positive, the algorithm marks the 
element as negative by multiplying it by -1 to indicate that abs(arr[i]) has been encountered.


4. Return the result: After iterating through the array, the algorithm returns the list of two repeated numbers.

Intuition:

1. By using the array itself to keep track of visited elements, the algorithm 
efficiently identifies the repeated elements. Each number from 1 to n in the array 
should be visited once. If a number is encountered a second time, it implies that the 
element is a repeating element.

2. By checking whether the value at the index abs(arr[i]) is negative, 
the algorithm can identify which elements have been visited more than once and 
therefore find the two repeating elements.

Complexity:
Time Complexity: The algorithm has a time complexity of O(n), as it involves a 
single pass through the array (of length n + 2), which is linear time.

Space Complexity: The space complexity is O(1) since the algorithm only uses the 
given array for marking visited elements and keeps track of only the two repeating 
numbers in a list. No additional data structures are needed.
*/
// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // Your code here
        vector<int> ans;
        for(int i=0;i<n+2;i++){
            if(arr[abs(arr[i])]<0){
                ans.push_back(abs(arr[i]));
            }else{
                arr[abs(arr[i])]*=-1;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}

// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1