//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // creating vector for inserting both array element
            vector <long long> v;
            
            // Inserting 1st Array element
            for(int i=0;i<n;i++)
            {
                v.push_back(arr1[i]);
            }
            // Inserting 2nd Array element
            for(int i=0;i<m;i++)
            {
                v.push_back(arr2[i]);
            }
            
            // Sorting the whole vector array
            sort(v.begin(),v.end());
            
            // Inserting element in 1st Array with size "n" from vector v
            for(int i=0;i<n;i++)
            {
                arr1[i]=v[i];
            }
            // Inserting element in 2nd Array with size "n" from vector v
            for(int i=0;i<m;i++)
            {
                arr2[i]=v[n+i];
            }
            
            
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1?page=1&difficulty[]=2&status[]=solved&sortBy=submissions