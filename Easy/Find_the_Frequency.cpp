//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

/*Function to find frequency of x
* x : element whose frequency is to be found
* v : input vector
*/

// Brute Force Approach
// Time complexity --> O(nlogn) and Space --> O(n)
// int findFrequency(vector<int> v, int x){
//     // Your code here
//     map<int,int> mp;
//     for(int i=0;i<v.size();i++)
//     {
//         mp[v[i]]++;
//     }
//     for(auto it: mp)
//     {
//         if(it.first==x)
//         {
//             return it.second;
//         }
//     }
//     return 0;
// }

// Optimized Approach
// Time complexity --> O(n) and Space --> O(1)
int findFrequency(vector<int> v, int x){
    // Your code here
    int count=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==x)
        {
            count++;
        }
        
    }
    return count;
}




//{ Driver Code Starts.
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    
	    // Declaring vector 
	    vector<int> v;
	        
	    // Taking vector element input
	    for(int i = 0;i<N;i++){
	        int k;
	        cin >> k;
	        v.push_back(k);
	    }
	    
	    // element whose frequency to be find
	    int x;
	    cin >> x;
	    cout << findFrequency(v, x) << endl;
	}
	
	return 0;
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/find-the-frequency/1