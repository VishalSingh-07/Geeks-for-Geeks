/*
Sorting Elements of an Array by Frequency

Given an array of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.

Example 1:

Input:
N = 5
A[] = {5,5,4,6,4}
Output: 4 4 5 5 6

Explanation: The highest frequency here is
2. Both 5 and 4 have that frequency. Now
since the frequencies are same then 
smallerelement comes first. So 4 4 comes 
firstthen comes 5 5. Finally comes 6.

The output is 4 4 5 5 6.


Example 2:

Input:
N = 5
A[] = {9,9,9,2,5}
Output: 9 9 9 2 5

Explanation: The highest frequency here is
3. The element 9 has the highest frequency
So 9 9 9 comes first. Now both 2 and 5
have same frequency. So we print smaller
element first.

The output is 9 9 9 2 5.
Y


our Task:

You only need to complete the function sortByFreq that takes arr, and n as parameters and returns the sorted array.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N). 

Constraints:
1 ≤ N ≤ 105
1 ≤ Ai ≤ 105 
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(n)
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    static bool Comparator(pair<int,int> &a, pair<int,int>&b)
    {
        if(a.second==b.second)
        {
            return a.first< b.first;
        }
        return a.second>b.second;
    }
    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto x: mp)
        {
            v.push_back({x.first,x.second});
        }
        sort(v.begin(),v.end(),Comparator);
        for(auto it: v)
        {
            while(it.second)
            {
                ans.push_back(it.first);
                it.second--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends

/*
1. Question link -- https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1

2. Solution link -- https://leetcode.com/problems/sort-array-by-increasing-frequency/solutions/3329127/easy-c-solution-simple-to-understand-approach-optimized-approach-dry-run/
*/