/*
Minimum Integer

You are given an array A of size N. Let us denote S as the sum of all integers present in the array. Among all integers present in the array, find the minimum integer X such that S ≤ N*X.

Example 1:

Input:
N = 3,
A = { 1, 3, 2}
Output:
2
Explanation:
Sum of integers in the array is 6.
since 6 ≤ 3*2, therefore 2 is the answer.


Example 2:

Input:
N = 1,
A = { 3 }
Output:
3



Explanation:
3 is the only possible answer
Your Task:
The task is to complete the function minimumInteger() which takes an integer N and an integer array A as input parameters and returns the minimum integer which satisfies the condition.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤  N ≤ 105
1 ≤  Ai ≤ 109
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


/*
Minimum Integer ✅

1. Just Traverse the Array and find the Sum first
2. Find all Elements which follow the condition N*A[i]>=sum
3. Now, take minimum out of them following above conditions.

NOTE : Plz take N*1LL*A[i] and Sum as long long since 
multiplication can go above 1e9 can lead to Integer Overflow.
*/
// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
  public:
    int minimumInteger(int n, vector<int> &a) {
        // code here
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int x=a[i];
            if(sum <= n*1LL*x)
            {
                ans=min(ans,x);
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.minimumInteger(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/1ccf56f107bcb24242469ea45c02f852165a2184/1