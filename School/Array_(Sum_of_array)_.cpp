//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int getSum(int a[], int n) {
        // Your code goes here
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        return sum;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.getSum(a, n) << endl;
    }

    return 0;
}
// } Driver Code Ends
// Question Link: -- https://practice.geeksforgeeks.org/problems/c-arrays-sum-of-array-set-14805/1?page=1&difficulty[]=-2&status[]=solved&category[]=Arrays&sortBy=submissions