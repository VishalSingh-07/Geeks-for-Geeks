//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// Time complexity --> O(n^2) and Space --> O(1)
// class Solution{
//   public:
//      // Function to find majority element in the array
//     // a: input array
//     // size: size of input array
//     int majorityElement(int a[], int size)
//     {
//         // your code here
//         int maxcount=0;
//         int index=-1;
//         for(int i=0;i<size;i++)
//         {
//             int count=0;
//             for(int j=0;j<size;j++)
//             {
//                 if(a[i]==a[j])
//                 {
//                     count++;
//                 }
//             }
            
//             // update the maxcount if count of current element is greater
            
//             if(count>maxcount)
//             {
//                 maxcount=count;
//                 index=i;
//             }
//         }
        
//         if(maxcount>size/2)
//         {
//             return a[index];
//         }
//         return -1;
//     }
// };

// -----------Above code is not working due high complexity but it is one of the approach




// ---------Working Code------------------


//Time complexity ---> O(n) and space ---> O(n/2)~ O(n)
// class Solution{
//   public:
//      // Function to find majority element in the array
//     // a: input array
//     // size: size of input array
//     int majorityElement(int a[], int size)
//     {
        
//         // your code here
//         map<int,int> mp;
        
//         for(int i=0;i<size;i++)
//         {
//             mp[a[i]]++;
            
//             if(mp[a[i]]>size/2)
//             {
//                 return a[i];
//             }
//         }
//         return -1;
        
//     }
// };


// Optimizate the code for the above to reduce the space complexity, we use moore's voting algorithm

// Using Moore's Voting Algorithm (Time complexity --> O(n) and space --> O(1))

/*
if the majority elemeny was x, and it by any chance appears on the 
left prefix, then it count at max can be (lenOfLeftPrefix/2). So since
it has to appear more than N/2 times, it is bound to appear as a majority
in the last suffix. Dry run multiple examples to get this clear! if it does not appears on left as majority, then it is quite clear that it will
be the majority at right.
*/

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        // your code here
        int count=0,candidate=0;
        for(int i=0;i<size;i++)
        {
            if(count==0)
            {
                candidate=a[i];
            }
            if(candidate==a[i])
            {
                count+=1;
            }
            else
            {
                count-=1;
            }
        }
        
        count=0;
        for(int i=0;i<size;i++)
        {
            if(a[i]==candidate)
            {
                count++;
            }
        }
        if(count>size/2)
        {
            return candidate;
        }
        else
        {
            return -1;
        }
        
    }
};


//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends


// Question link ---https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1?page=1&status[]=bookmarked&sortBy=submissions