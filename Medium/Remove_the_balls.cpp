/*
Remove the balls
MediumAccuracy: 58.66%Submissions: 12K+Points: 4
Unlock your coding potential - join our Hiring Coding Contest and land your dream job!  

Imagine an imaginary array of length N containing balls. Given 2 arrays color and radius of length N each, where color[i] represents the color of the ith ball while radius[i] represents the radius of ith ball. If two consecutive balls have the same color and size, both are removed from the array. Geek wants to know the length of the final imaginary array.

Example 1:

Input:
N = 3
color[] = {2, 2, 5}
radius[] = {3, 3, 4}
Output: 
1
Explanation: 
First ball and second ball have same color 2 and 
same radius 3.So,after removing only one ball 
is left.It could not be removed from the array. 
Hence, the final array has length 1.


Example 2:

Input:
N = 4
color[] = {1, 3, 3, 1}
radius[] = {2, 5, 5, 2}
Output:
0
Explanation:
Ball 2 and ball 3 have same color 3 and same radius
5.So,they are removed. Now, we have got our
color[]={1, 1} and radius[]={2, 2}.Both the left
balls are consecutive now and they are having
same color and radius. So,these two balls are
removed as well. Now,we are left with empty
final array. Hence, the length of final array is 0.


Your Task: 
You don't need to read input or print anything. Your task is to complete the function finLength(), which takes integer N and array color[ ] and array radius[ ] as input parameters and returns the size of the final imaginary array.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ N ≤ 105
1 ≤ color[i] ≤ 109
1 ≤ radius[i] ≤ 109                                                                                                                       
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
  public:
    int finLength(int n, vector<int> color, vector<int> radius) {
        stack<int> cl;
        stack<int> rd;
        cl.push(color[0]);
        rd.push(radius[0]);
        for(int i=1;i<n;i++)
        {
            if(cl.size()>0 && (cl.top()==color[i] && rd.top()==radius[i]))
            {
                cl.pop();
                rd.pop();
            }
            else
            {
                cl.push(color[i]);
                rd.push(radius[i]);
            }
        }
        return cl.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/546ea68f97be7283a04ddcc8057e09b46a686471/1