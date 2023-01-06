//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Brute Force Approach
// Time complexity --> O(n^2)+O(nlogn) ~ O(n^2) and space --> O(n)
class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here 
        sort(A,A+N);
        sort(B,B+M);
        vector<pair<int, int>> p;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(A[i]+B[j]==X)
                {
                    p.push_back({A[i],B[j]});
                    // p.emplace_back(A[i],B[j]);
                }
        
            }
        }
        return p;
    }
};


// Optimized Approach

// Time complexity --> O(n)+O(nlogn) ~~ O(nlogn)  and space --> O(n)
// class Solution{
//     public:
//     vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
//     {
//         // Your code goes here  
//         vector<pair<int, int>> p;
//         unordered_set<int> s; // inserting all element of first array in a hash
//         for(int i=0;i<N;i++)
//         {
//             s.insert(A[i]);
//         }
        
//         // Subtract sum from second array element one by one and check it's present in array first or not
        
//         for(int j=0;j<M;j++)
//         {
//             if(s.find(X-B[j])!=s.end())
//             {
//                 p.push_back({X-B[j],B[j]});
//             }
//         }
        
//         sort(p.begin(),p.end());
        
//         return p;
//     }
// };


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1