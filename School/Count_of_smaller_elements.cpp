//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int countOfElements(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        cin >> x;

        cout << countOfElements(arr, n, x) << endl;
    }
    return 0;
}
// } Driver Code Ends


int countOfElements(int arr[], int n, int x) 
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=x)
        {
            count++;
        }
    }
    return count;
    
}

// Question Link: -- https://practice.geeksforgeeks.org/problems/count-of-smaller-elements5947/1?page=1&difficulty[]=-2&status[]=solved&category[]=Arrays&sortBy=submissions