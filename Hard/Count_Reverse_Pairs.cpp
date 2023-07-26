//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++


// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
// class Solution {
//   public:
//     int countRevPairs(int n, vector<int> arr) {
//         // Code here
//         int count=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(arr[i]>2*arr[j])
//                 {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };


// Optimized Approach
// Time complexity -> O(2nlogn) and Space -> O(n)
class Solution {
    private:
        void merge(vector<int> &arr, int low, int mid, int high)
        {
            vector<int> temp;
            int left=low;
            int right=mid+1;
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
            for(int i=low;i<=high;i++)
            {
                arr[i]=temp[i-low];
            }
        }
        int countPairs(vector<int> &arr, int low, int mid, int high)
        {
            int count=0;
            int right=mid+1;
            for(int i=low;i<=mid;i++)
            {
                while(right<=high && arr[i]>2*arr[right])
                {
                    right++;
                }
                count+=right-(mid+1);
            }
            return count;
        }
        int mergeSort(vector<int> &arr, int low, int high)
        {
            int count=0;
            if(low>=high)
            {
                return count;
            }
            int mid=low+(high-low)/2;
            count+=mergeSort(arr,low,mid);
            count+=mergeSort(arr,mid+1,high);
            count+=countPairs(arr,low,mid,high);
            merge(arr,low,mid,high);
            return count;
        }
    public:
        int countRevPairs(int n, vector<int> arr) {
        // Code here
        return mergeSort(arr,0,n-1);
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends


/*
1. Question link -- https://practice.geeksforgeeks.org/problems/count-reverse-pairs/1

2. Solution link -- https://leetcode.com/problems/reverse-pairs/solutions/3819575/2-approach-easy-c-solution-brute-force-and-optimized-approach/

3. Video link -- https://youtu.be/0e4bZaP3MDI
*/