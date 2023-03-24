/*
Longest consecutive subsequence

Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.


Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findLongestConseqSubseq() which takes the array arr[] and the size of the array as inputs and returns the length of the longest subsequence of consecutive integers. 


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <= N <= 105
0 <= a[i] <= 105
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(n^3) and Space -> O(1)
class Solution{
    private:
    bool arrayContains(int arr[],int n, int x)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]==x)
            {
                return true;
            }
        }
        return false;
    }
    public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        //Your code here
        int longestStreak=0;
        for(int i=0;i<n;i++)
        {
            int currentElement=arr[i];
            int currentStreak=1;
            while(arrayContains(arr,n,currentElement+1))
            {
                currentElement++;
                currentStreak++;
                
            }
            longestStreak=max(currentStreak,longestStreak);
            
        }
        return longestStreak;
    }
};

// Above code give time limit Exceeded due to high complexity O(n^3)

// Better Approach
// Time complexity -> O(nlogn) and Space -> O(1)
class Solution{
    public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        //Your code here
        if(n==0)
        {
            return 0;
        }
        sort(arr,arr+n);
        int longestStreak=1,currentStreak=1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=arr[i-1])
            {
                if(arr[i]==arr[i-1]+1)
                {
                    currentStreak++;
                }
                else
                {
                     
                    currentStreak=1;
                }
            }
            longestStreak=max(currentStreak,longestStreak);
            
        }
        return longestStreak;
    }
};


// Optimized Approach [Using Unorderd Map]
// Time complexity -> O(n) and Space -> O(n)
class Solution{
    public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        //Your code here
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        int longestStreak=0;
        for(int i=0;i<n;i++)
        {
            int currentElement=arr[i];
            int previousElement=currentElement-1;
            int currentStreak=1;
            if(mp.find(previousElement)==mp.end())
            {
                while(mp.find(currentElement+1)!=mp.end())
                {
                    currentElement++;
                    currentStreak++;
                }
            }
            longestStreak=max(currentStreak,longestStreak);
            
        }
        return longestStreak;
    }
};


// Optimized Approach [Using Unordered Set]

// Time complexity -> O(n) and Space -> O(n)
class Solution{
    public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        //Your code here
        unordered_set<int> s;
        for(int i=0;i<n;i++)
        {
            s.insert(arr[i]);
        }
        int longestStreak=0;
        for(int i=0;i<n;i++)
        {
            int currentElement=arr[i];
            int previousElement=currentElement-1;
            int currentStreak=1;
            if(s.find(previousElement)==s.end())
            {
                while(s.find(currentElement+1)!=s.end())
                {
                    currentElement++;
                    currentStreak++;
                }
            }
            longestStreak=max(currentStreak,longestStreak);
            
        }
        return longestStreak;
    }
};


//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends

/*
1. Question link -- https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

2. My Solution link -- https://leetcode.com/problems/longest-consecutive-sequence/solutions/3332851/4-approach-easy-c-solution-brute-force-better-and-optimized-approach/

3. Video Link --
      a) https://youtu.be/pLzOp2_Y9Vk
      
      b) https://youtu.be/qgizvmgeyUM
*/