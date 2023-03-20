/*
Container With Most Water

Given N non-negative integers a1,a2,....an where each represents a point at coordinate (i, ai). N vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i,0). Find two lines, which together with x-axis forms a container, such that it contains the most water.

Note : In Case of single verticle line it will not be able to hold water.

Example 1:

Input:
N = 4
a[] = {1,5,4,3}
Output: 6
Explanation: 5 and 3 are distance 2 apart.
So the size of the base = 2. Height of
container = min(5, 3) = 3. So total area
= 3 * 2 = 6.


Example 2:

Input:
N = 5
a[] = {3,1,2,4,5}
Output: 12
Explanation: 5 and 3 are distance 4 apart.
So the size of the base = 4. Height of
container = min(5, 3) = 3. So total area
= 4 * 3 = 12.


Your Task :
You only need to implement the given function maxArea. Do not read input, instead use the arguments given in the function and return the desired output. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1<=N<=105
1<=A[i]<=100
*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
// long long maxArea(long long A[], int len)
// {
//     // Your code goes here
//     long long maxAr=0;
//     for(int i=0;i<len;i++)
//     {
//         for(int j=i+1;j<len;j++)
//         {
//             long long width=j-i;
//             maxAr=max(maxAr,min(A[j],A[i])*width);
//         }
//     }
//     return maxAr;
// }

// Above code ❌ give time limit Exceeded due to high complexity O(n^2)


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
long long maxArea(long long A[], int len)
{
    // Your code goes here
    long long maxAr=0;
    int left=0,right=len-1;
    for(int i=0;i<len;i++)
    {
        long long width=right-left;
        maxAr=max(maxAr,min(A[right],A[left])*width);
        if(A[left]>A[right])
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return maxAr;
}

// OR

// long long maxArea(long long A[], int len)
// {
//     // Your code goes here
//     long long maxAr=0;
//     int left=0,right=len-1;
//     while(left<right)
//     {
//         long long width=right-left;
//         maxAr=max(maxAr,min(A[right],A[left])*width);
//         if(A[left]>A[right])
//         {
//             right--;
//         }
//         else
//         {
//             left++;
//         }
//     }
//     return maxAr;
// }






//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends

/*
1. Question link -- https://practice.geeksforgeeks.org/problems/container-with-most-water0535/1

2. Solution link -- https://leetcode.com/problems/container-with-most-water/solutions/3315756/2-approach-easy-c-solution-brute-force-and-optimized-approach/

3. Video link -- https://youtu.be/aO9eAw1wKvE
*/