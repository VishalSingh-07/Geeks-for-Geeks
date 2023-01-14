//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int temp[r-l+1];
         int pos=0,i=l,j=m+1;
         while(i<=m and j<=r)
         {
             if(arr[i]<=arr[j])
             {
                 temp[pos++]=arr[i++];
             }
             else
             {
                 temp[pos++]=arr[j++];
             }
             
         }
         while(i<=m)
         {
             temp[pos++]=arr[i++];
         }
         while(j<=r)
         {
             temp[pos++]=arr[j++];
         }
         for(int i=0;i<pos;i++)
         {
             arr[i+l]=temp[i];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        
        if(l<r)
        {
            int mid=l+(r-l)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
        
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/merge-sort/1