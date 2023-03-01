//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
      
        Rearrange( arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends


// Approach 1
// Time Complexity -> O(n)  and Space -> O(n)
void Rearrange(int arr[], int n)
{
    // Your code goes here
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            ans.push_back(arr[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=0)
        {
            ans.push_back(arr[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=ans[i];
    }
    
}

// Approach 2
// Time Complexity -> O(n)  and Space -> O(n)

void Rearrange(int arr[], int n)
{
        queue <int> positive;
	    queue <int> negative;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0)
	        {
	            positive.push(arr[i]);
	        }
	        else
	        {
	            negative.push(arr[i]);
	        }
	        
	    }
	    for(int i=0;i<n;)
	    {
	        
	        while(!negative.empty())
	        {
	            arr[i++]=negative.front();
	            negative.pop();
	        }
	        while(!positive.empty())
	        {
	            arr[i++]=positive.front();
	            positive.pop();
	        }
	        
	    }
	    
}




// Approach 3
// Time complexity -->(nlogn) and Space --> O(logn)
void reverse(int arr[], int l, int r) 
{ 
    if (l < r) { 
        swap(arr[l], arr[r]); 
        reverse(arr, ++l, --r); 
    } 
} 
  
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i = l; // Initial index of 1st subarray 
    int j = m + 1; // Initial index of IInd 
  
    while (i <= m && arr[i] < 0) 
        i++; 
  
    // arr[i..m] is positive 
  
    while (j <= r && arr[j] < 0) 
        j++; 
  
    // arr[j..r] is positive 
  
    // reverse positive part of left sub-array (arr[i..m]) 
    reverse(arr, i, m); 
  
    // reverse negative part of right sub-array (arr[m+1..j-1]) 
    reverse(arr, m + 1, j - 1); 
  
    // reverse arr[i..j-1] 
    reverse(arr, i, j - 1); 
} 
  
// Function to Rearrange positive and negative 
// numbers in a array 
void RearrangePosNeg(int arr[], int l, int r)
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        RearrangePosNeg(arr, l, m); 
        RearrangePosNeg(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void Rearrange(int arr[], int n)
{
    RearrangePosNeg(arr, 0, n - 1); 
}

// Question link -- https://practice.geeksforgeeks.org/problems/arranging-the-array1131/1