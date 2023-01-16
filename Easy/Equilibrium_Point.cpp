//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

// Brute Force Approach

// Time complexity --> O(n^2) and Space --> O(1)
// class Solution{
//     public:
//     // Function to find equilibrium point in the array.
//     // a: input array
//     // n: size of array
//     int equilibriumPoint(long long a[], int n) {
    
//         // Your code here
//         for(int i=0;i<n;i++)
//         {
//             int leftsum=0;
//             int rightsum=0;
//             for(int j=0;j<i;j++)
//             {
//                 leftsum=leftsum+a[j];
//             }
//             for(int k=i+1;k<n;k++)
//             {
//                 rightsum=rightsum+a[k];
//             }

//             if(leftsum==rightsum)
//             {
//                 return i+1;
//             }
//         }
//         return -1;
//     }

// };

// Above Code is not working because it has high complexity O(n^2) 
// that why it showing time limit exceeded but solution is correct.

// Optimized Approach
// Time complexity --> O(n) and Space --> O(1)

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int sum=0,leftsum=0,rightsum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        rightsum=sum;
        for(int i=0;i<n;i++)
        {
            leftsum+=a[i];
            if(leftsum==rightsum)
            {
                return i+1;
            }
            rightsum-=a[i];
        }
        return -1;
    }

};



//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1

// Resource Link -- https://leetcode.com/problems/find-pivot-index/solutions/3058088/two-approach-to-solve-a-problem-easy-solution-brute-force-optimized-approach-dry-run/