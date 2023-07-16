//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]>arr[j])
                {
                    count++;
                }
            }
        }
        return count;
    }

};

// Above code give time limit Exceeded due to high time complexity O(n^2)


// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(n)
class Solution{
    private:
    long long merge(long long arr[], long long low, long long mid, long long high)
    {
        vector<long long> temp;
        long long left=low;
        long long right=mid+1LL;
        long long count=0;
        while(left<=mid && right<=high)
        {
            if(arr[left]<=arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                count+=(mid-left+1LL);
                right++;
            }
        }
        while(left<=mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high)
        {
            temp.push_back(arr[right]);
            right++;
        }
        for(long long i=low;i<=high;i++)
        {
            arr[i]=temp[i-low];
        }
        return count;
    }
    long long int mergeSort(long long int arr[], long long int low, long long int high)
    {
        long long int count=0;
        if(low>=high)
        {
            return count;
        }
        long long int mid= low + (high - low) / 2;
        count+=mergeSort(arr,low,mid);
        count+=mergeSort(arr,mid+1,high);
        count+=merge(arr,low,mid,high);
        return count;
    }
    public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        return mergeSort(arr,0,n-1);
        
    }

};



//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends

/*
1. Question link -- https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

2. Video link -- https://youtu.be/AseUmwVNaoY
*/