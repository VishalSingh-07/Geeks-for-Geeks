//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

// Brute Force Approach

// Time complexity --> O(n) + O(nlogn) = O(nlogn) and Space --> O(n)
// class Solution{
//     public:
//     vector<long long int> twoOddNum(long long int Arr[], long long int N)  
//     {
//         // code here
//         map<long long int,long long int> mp;
//         vector<long long int> ans;
//         for(long long int i=0;i<N;i++)
//         {
//             mp[Arr[i]]++;
//         }
//         for(auto it: mp)
//         {
//             if(it.second%2!=0)
//             {
//                 ans.push_back(it.first);
//             }
//         }
//         sort(ans.begin(),ans.end(),greater<long long int>());
//         return ans;
//     }
// };


// Optimized Approach

// Time complexity --> O(n) and Space --> O(1)
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        // code here
        long long int val=0;
        for(int i=0;i<n;i++)
        {
            val^=arr[i];
        }
        long long int rsb=val&(-val); // mask of right most set bit
        long long int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            if((arr[i]&rsb)==0)
            {
                x^=arr[i];
            }
            else
            {
                y^=arr[i];
            }
        }
        return {max(x,y),min(x,y)};
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


// Question link -- https://practice.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1

// Video link -- https://youtu.be/qVakVOyuDFQ