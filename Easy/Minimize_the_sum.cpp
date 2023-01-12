//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++


/*
BRUTE FORCE : 
If you've observed testcases carefully and did a dry run once, then you'll find that to get the minimum sum, we have to add two SMALLEST number.

1. We'll sort the array and pick the first two numbers from the array.
2. Now remove that two number of array and push addition of them in array.
3. But to get minimum sum, we have to sort the array again.
4. Keep adding that sum to another variable as ANS.
 

TC :- O(n*n*logn) - n for FOR LOOP and nlogn for SORTING.
*/

//Time complexity --> O(n*nlogn) and Space --> O(1)
// class Solution {
// public:
//     int minimizeSum(int N, vector<int> arr) {
//         // code here
//         sort(arr.begin(),arr.end());
//         int ans=0;
//         for(int i=0;i<N-1;i++)
//         {
//             int sum=0;
//             sum+=arr[i]+arr[i+1];
//             arr.erase(arr.begin()+1);
//             arr.push_back(sum);
//             sort(arr.begin(),arr.end());
//             ans+=sum;
            
//         }
//         return ans;
//     }
// };

// Above code is not working because due to high complexity GFG Compiler show time limit exceeded


/*
Optimized Approach 

OBSERVATIONS : 

Now if you have idea about the MIN HEAP/priority queue than this data structure 
do the same work as pushing element and sorting but in O(logn) time.

1. Make one min heap and store all the elements of array in it.
2. We'll do some calculations till there is more than one element in queue.
3. Since top of heap will be storing the smallest element, we just simply pick 2 top elements for the addition.
4. Now add that addition to the ans.

TC : O(n*logn) - n for traversing heap and logn to push the element.

*/
// Time complexity --> O(nlogn) and Space --> O(n)
class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> h;
        for(int i=0;i<N;i++)
        {
            h.push(arr[i]);
        }
        
        int ans=0;
        while(h.size()>1)
        {
            int sum=h.top();
            h.pop();
            sum+=h.top();
            h.pop();
            h.push(sum);
            ans+=sum;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends