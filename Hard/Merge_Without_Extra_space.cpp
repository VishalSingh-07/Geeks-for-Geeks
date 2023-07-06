//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends

// Naive Approach
// Time complexity -> O((n + m)log(n + m)) and Space -> O(n + m)
// class Solution{
//     public:
//         //Function to merge the arrays.
//         void merge(long long arr1[], long long arr2[], int n, int m) 
//         { 
//             // creating vector for inserting both array element
//             vector <long long> v;
            
//             // Inserting 1st Array element
//             for(int i=0;i<n;i++)
//             {
//                 v.push_back(arr1[i]);
//             }
//             // Inserting 2nd Array element
//             for(int i=0;i<m;i++)
//             {
//                 v.push_back(arr2[i]);
//             }
            
//             // Sorting the whole vector array
//             sort(v.begin(),v.end());
            
//             // Inserting element in 1st Array with size "n" from vector v
//             for(int i=0;i<n;i++)
//             {
//                 arr1[i]=v[i];
//             }
//             // Inserting element in 2nd Array with size "n" from vector v
//             for(int i=0;i<m;i++)
//             {
//                 arr2[i]=v[n+i];
//             }
            
            
//         } 
// };


// Brute Force Approach
// Time complexity -> O(n+m) and Space -> O(n+m) 
// class Solution{
//     public:
//         //Function to merge the arrays.
//         void merge(long long arr1[], long long arr2[], int n, int m) 
//         { 
//             // code here 
//             long long arr3[n+m];
//             int left=0;
//             int right=0;
//             int index=0;
//             while(left<n && right<m)
//             {
//                 if(arr1[left]<=arr2[right])
//                 {
//                     arr3[index]=arr1[left];
//                     left++;
//                     index++;
//                 }
//                 else
//                 {
//                     arr3[index]=arr2[right];
//                     right++;
//                     index++; 
//                 }
//             }
//             while(left<n)
//             {
//                 arr3[index++]=arr1[left++];
//             }
//             while(right<m)
//             {
//                 arr3[index++]=arr2[right++];
//             }
            
//             for(int i=0;i<n+m;i++)
//             {
//                 if(i<n)
//                 {
//                     arr1[i]=arr3[i];
//                 }
//                 else
//                 {
//                     arr2[i-n]=arr3[i];
//                 }
//             }
//         } 
        
// };

// Optimized Approach 1 [Two Pointer]
// Time complexity -> O(min(n,m))+O(nlogn)+O(mlogm) and Space -> O(1) 
// class Solution{
//     public:
//         //Function to merge the arrays.
//         void merge(long long arr1[], long long arr2[], int n, int m) 
//         { 
//             // code here 
//             int left=n-1;
//             int right=0;
//             while(left>=0 && right<m)
//             {
//                 if(arr1[left]>arr2[right])
//                 {
//                     swap(arr1[left],arr2[right]);
//                     left--;
//                     right++;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             sort(arr1,arr1+n);
//             sort(arr2,arr2+m);
            
            
//         } 
        
// };



// Optimized Approach 2
// Time complexity -> O(log2(n+m)*O(n+m)) and Space -> O(1) 
class Solution{
    private:
        void swapIfGreater(long long arr1[], long long arr2[], int index1, int index2)
        {
            if(arr1[index1]>arr2[index2])
            {
                swap(arr1[index1],arr2[index2]);
            }
        }
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here
            int len=n+m;
            int gap=(len/2)+(len%2);
            while(gap>0)
            {
                int left=0;
                int right=left+gap;
                while(right<len)
                {
                    // arr1 and arr2 element
                    if(left<n && right>=n)
                    {
                        swapIfGreater(arr1, arr2,left,right-n);
                    }
                    // arr2 and arr2 element
                    else if(left>=n)
                    {
                       swapIfGreater(arr2, arr2,left-n,right-n); 
                    }
                    // arr1 and arr1 element
                    else
                    {
                       swapIfGreater(arr1, arr1,left,right); 
                    }
                    left++;
                    right++;
                }
                if(gap==1)
                {
                    break;
                }
                gap=(gap/2)+(gap%2);
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



// Question link -- https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

// Solution link -- https://leetcode.com/problems/merge-sorted-array/solutions/3727130/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/

// Video Link -- https://youtu.be/n7uwj04E0I4