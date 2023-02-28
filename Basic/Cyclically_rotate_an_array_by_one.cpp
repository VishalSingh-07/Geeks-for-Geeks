//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}

// } Driver Code Ends


//User function Template for C++


// Brute Force Approach
// Time complexity --> O(n) and Space --> O(n)
/*
Steps: --
Following are steps.
1) Store last element in a variable say x.
2) Shift all elements one position ahead.
3) Replace first element of array with x.
*/
void rotate(int arr[], int n)
{
    int temp[n];
    int x=arr[n-1];
    for(int i=0;i<n;i++)
    {
        temp[i+1]=arr[i];
    }
    temp[0]=x;
    for(int i=0;i<n;i++)
    {
        arr[i]=temp[i];
    }
    
}


// Optimized Approach
// Time complexity --> O(n) and Space --> O(1)
void rotate(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        swap(arr[i],arr[n-1]);
    }
    
}


// --OR--
void rotate(int arr[], int n)
{
    int x=arr[n-1];
    for(int i=n-1;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=x;
    
}

// Question link -- https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1