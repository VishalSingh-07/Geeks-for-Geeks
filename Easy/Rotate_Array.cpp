// In this Question we have to rotate an array anti-clockwise [Counter clockwise]

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(n)
// class Solution{
//     public:
    
//     //Function to rotate an array by d elements in counter-clockwise direction. 
//     void rotateArr(int arr[], int d, int n){
//         // code here
//         int temp1[d],temp2[n],a=0,b=0,c=0;
//         if(n<=d)
//         {
//             d=d%n;
//         }
//         for(int i=0;i<d;i++)
//         {
//             temp1[a++]=arr[i];
//         }
//         for(int i=d;i<n;i++)
//         {
//             temp2[b++]=arr[i];
//         }
//         for(int i=0;i<b;i++)
//         {
//             arr[c++]=temp2[i];
//         }
//         for(int i=0;i<a;i++)
//         {
//             arr[c++]=temp1[i];
//         }
        
//     }
// };


// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)

/*
Explanation
arr = a1,a2,a3,a4,a5,a6,a7,a8
d=3

Step 1: Reverse Subarray a[1:d] and subarray a[d+1:n]

arr -> a3,a2,a1,a8,a7,a6,a5,a4

Step 2: Reverse the whole array

arr -> a4,a5,a6,a7,a8,a1,a2,a3 [Answer]
*/
class Solution{
    public:
    
    void reverse(int arr[],int start, int end)
    {
        while(start<end)
        {
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        d=d%n;
        reverse(arr,0,d-1);
        reverse(arr,d,n-1);
        reverse(arr,0,n-1);
        
        
    }
};


//{ Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
// } Driver Code Ends


// Question link -- https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1