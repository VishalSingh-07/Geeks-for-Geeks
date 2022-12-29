//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        int sum=n*(n+1)/2; // sum of the n integer
        int array_sum=0;
        int missing_number;
        
        for(auto it :array) // Traversing a dynamic array
        {
            array_sum=array_sum+it; // finding the sum of the dynamic array
        }
        if(array_sum==sum)
        {
            return -1;
        }
        else
        {
            missing_number=sum-array_sum;
            return missing_number;
            
        }
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1?page=1&difficulty[]=0&status[]=solved&category[]=Arrays&sortBy=submissions