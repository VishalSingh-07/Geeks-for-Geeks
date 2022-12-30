//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> minAnd2ndMin(int a[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        vector<int> ans = minAnd2ndMin(a, n);
        if (ans[0] == -1)
            cout << -1 << endl;
        else 
            cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
// } Driver Code Ends


// Approach 1 --
// Time complexity --> O(n) and O(1)
/*
Algorithm --

1) Initialize both first and second smallest as INT_MAX
   first = second = INT_MAX
2) Loop through all the elements.
   a) If the current element is smaller than first, then update first 
       and second. 
   b) Else if the current element is smaller than second then update 
    second
*/
// vector<int> minAnd2ndMin(int a[], int n) {
    
//     int smallest=INT_MAX;
//     int second_smallest=INT_MAX;
    
//     if(n<2)
//     {
//         return {-1,-1};
//     }
    
//     for(int i=0;i<n;i++) // traversing the array to find smallest element.
//     {
//         if(a[i]<smallest)
//         {
           
//             smallest=a[i];
            
//         }
//     }
//     for(int i=0;i<n;i++) // traversing the array to find second smallest element
//     {
//         if(a[i]<second_smallest && a[i]>smallest)
//         {
//             second_smallest=a[i];
            
//         }
//     }
    
//     if(smallest==INT_MAX || second_smallest==INT_MAX)
//     {
//         return {-1,-1};
//     }
//     else
//     {
//         return {smallest,second_smallest};
//     }
    
    
    
// }



// Approach 2
// Time complexity --> O(n) and space -->O(1)
vector<int> minAnd2ndMin(int a[], int n) {
    vector<int> v;
    sort(a,a+n);
    v.push_back(a[0]); // pushing smallest element in the array
    
    for(int i=1;i<n;i++)
    {
        if(a[i-1]!=a[i]) // checking not contain duplicate of smallest element
        {
            v.push_back(a[i]);
            return v;
        }
    }
    
    return {-1,-1};
}


// Question Link -- https://practice.geeksforgeeks.org/problems/find-the-smallest-and-second-smallest-element-in-an-array3226/1?page=2&difficulty[]=-1&category[]=Arrays&sortBy=submissions