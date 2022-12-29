//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        int mid, l, h;
        l=0;
        h=n-1;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(k==arr[mid])
            {
                return mid;
            }
            else if(k < arr[mid])
            {
                h=mid-1;
            }
            else if(k>arr[mid])
            {
                l=mid+1;
            }
        }
        return -1;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1?page=1&difficulty[]=-1&status[]=solved&category[]=Arrays&sortBy=submissions