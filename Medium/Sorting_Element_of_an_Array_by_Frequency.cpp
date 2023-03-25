/*
Sorting Elements of an Array by Frequency

Given an array A[] of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
For each testcase, in a new line, print each sorted array in a seperate line. For each array its numbers should be seperated by space.

Constraints:
1 ≤ T ≤ 70
1 ≤ N ≤ 130
1 ≤ Ai ≤ 60 

Example:
Input:
2
5
5 5 4 6 4
5
9 9 9 2 5

Output:
4 4 5 5 6
9 9 9 2 5

Explanation:
Testcase1: The highest frequency here is 2. Both 5 and 4 have that frequency. Now since the frequencies are same then smaller element comes first. So 4 4 comes first then comes 5 5. Finally comes 6.
The output is 4 4 5 5 6.

Testcase2: The highest frequency here is 3. The element 9 has the highest frequency. So 9 9 9 comes first. Now both 2 and 5 have same frequency. So we print smaller element first.
The output is 9 9 9 2 5.
*/

#include <bits/stdc++.h>
using namespace std;


// Optimized Approach
// Time complexity -> O(nlogn)  and Space -> O(n)

static bool comparator(pair<int,int> &a, pair<int,int> &b)
{
    if(a.second==b.second)
    {
        return a.first<b.first;
    }
    return a.second>b.second;
}

vector<int> solve(int arr[], int n)
{
    unordered_map<int,int> mp;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    vector<pair<int,int>> p;
    for(auto it: mp)
    {
        p.push_back({it.first,it.second});
    }
    sort(p.begin(),p.end(),comparator);
    for(auto it: p)
    {
        while(it.second)
        {
            ans.push_back(it.first);
            it.second--;
        }
    }
    return ans;
    
}
int main() 
{
	//code
	int t;
    cin>>t;
    
    while(t--)
    {
        
        int n;
        cin>>n;
        
        int arr[n];
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        vector<int> v=solve(arr,n);
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


// 1. Question link -- https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0

// 2. Solution link -- https://leetcode.com/problems/sort-array-by-increasing-frequency/solutions/3329127/easy-c-solution-simple-to-understand-approach-optimized-approach-dry-run/