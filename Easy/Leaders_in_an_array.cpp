//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

// Brute Force Approach
// Time complexity --> O(n^2) and Space --> O(n)
// class Solution{
//     //Function to find the leaders in the array.
//     public:
//     vector<int> leaders(int arr[], int n){
//         // Code here
//         vector<int> ans;
        
//         for(int i=0;i<n;i++)
//         {
//             int j;
//             for(j=i+1;j<n;j++)
//             {
//                 if(arr[j]>=arr[i])
//                 {
//                     break;
//                 }
//             }
//             if(j==n)
//             {
//                 ans.push_back(arr[i]);
//             }
//         }
       
//         return ans;
        
//     }
// };

// Above code give time limit Exceeded


// Optimized Approach
// Time complexity --> O(n) and Space --> O(n)
class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int arr[], int n){
        // Code here
        vector<int> ans;
        int max=arr[n-1];
        ans.push_back(max);
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>=max)
            {
                ans.push_back(arr[i]);
                max=arr[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};




//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

// Article Link -- https://www.geeksforgeeks.org/leaders-in-an-array/