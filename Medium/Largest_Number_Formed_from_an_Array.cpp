/*
Largest Number formed from an Array

Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.The result is going to be very large, hence return the result in the form of a string.


Example 1:

Input: 
N = 5
Arr[] = {3, 30, 34, 5, 9}
Output: 9534330
Explanation: Given numbers are {3, 30, 34,
5, 9}, the arrangement 9534330 gives the
largest value.



Example 2:

Input: 
N = 4
Arr[] = {54, 546, 548, 60}
Output: 6054854654
Explanation: Given numbers are {54, 546,
548, 60}, the arrangement 6054854654 
gives the largest value.


Your Task:  

You don't need to read input or print anything. Your task is to complete the function printLargest() which takes the array of strings arr[] as parameter and returns a string denoting the answer.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 105
0 ≤ Arr[i] ≤ 1018
Sum of all the elements of the array is greater than 0.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(1)
// class Solution{
// public:
// 	// The main function that returns the arrangement with the largest value as
// 	// string.
// 	// The function accepts a vector of strings
	
// 	static bool custom_comparator(string &a, string &b)
// 	{
// 	    if(a+b>b+a)
// 	    {
// 	        return true;
// 	    }
// 	    return false;
// 	}
	
// 	string printLargest(vector<string> &arr) {
// 	    // code here
// 	    sort(arr.begin(),arr.end(),custom_comparator);
// 	    string ans="";
// 	    for(string x: arr)
// 	    {
// 	        ans+=x;
// 	    }
// 	    int start=0;
// 	    while(ans[start]=='0' && start<ans.size()-1)
// 	    {
// 	        start++;
// 	    }
// 	    return ans.substr(start);
// 	}
// };


// OR --

class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	
	static bool custom_comparator(string a, string b)
	{
	    string ab=a.append(b);
	    string ba=b.append(a);
	    
	    return ab.compare(ba)>0?1:0;
	  
	}
	
	string printLargest(vector<string> &arr) {
	    // code here
	    sort(arr.begin(),arr.end(),custom_comparator);
	    string ans="";
	    for(string x: arr)
	    {
	        ans+=x;
	    }
	    return ans;
	}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

/*
1. Question link -- https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

2. My Solution link -- https://leetcode.com/problems/largest-number/solutions/3311857/easy-c-solution-optimized-approach-t-c-o-nlogn-and-s-c-o-n/

3. Video Link -- https://youtu.be/2vcOnre_tMM
*/