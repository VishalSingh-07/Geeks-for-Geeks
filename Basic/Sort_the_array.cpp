//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Time complexity --> O(n*logn) and Space --> O(1)
class Solution{
    public:
    vector<int> sortArr(vector<int>arr, int n){
        //complete the function here
        sort(arr.begin(),arr.end());
        return arr;
    
    }
};




//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        Solution ob;
        vector<int>v = ob.sortArr(s, n);
        for(auto i : v)
            cout << i << ' ';
        cout << endl;
    }
return 0;
}


// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/sort-the-array0055/1