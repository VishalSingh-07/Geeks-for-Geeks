//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

// Using Sorting Function
// Time complexity --> O(nlogn) and Space --> O(1)
// class Solution
// {
//     public:
//     void sort012(int a[], int n)
//     {
//         // code here 
//         sort(a,a+n);
//     }
    
// };



// Using Counting Approach
// Time complexity --> O(n) + O(n) ~ O(2n) and Space --> O(1)
// class Solution
// {
//     public:
//     void sort012(int a[], int n)
//     {
//         // code here 
//         int i,countzero=0, countone=0,counttwo=0;
//         for(int i=0;i<n;i++)
//         {
//             if(a[i]==0)
//             {
//                 countzero++;
               
//             }
//             else if(a[i]==1)
//             {
//                 countone++;
                
//             }
//             else if(a[i]==2)
//             {
//                 counttwo++;
        
//             }
//         }
//         i=0;
//         while(countzero>0)
//         {
//             a[i]=0;
//             countzero--;
//             i++;
//         }
//         while(countone>0)
//         {
//             a[i]=1;
//             countone--;
//             i++;
//         }
//         while(counttwo>0)
//         {
//             a[i]=2;
//             counttwo--;
//             i++;
//         } 
//     }
    
// };

// Using Pointer Approach (Dutch National Flag Algorithm)
// Time complexity --> O(n) and Space -->O(1)
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int l=0;
        int h=n-1;
        int mid=0;

        while(mid<=h)
        {
            if(a[mid]==0)
            {
                swap(a[l],a[mid]);
                l++;
                mid++;
            }
            else if(a[mid]==1)
            {
                mid++;

            }
            else if(a[mid]==2)
            {
                swap(a[mid],a[h]);
                h--;
            }
        }
    }
    
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1?page=1&difficulty[]=0&status[]=solved&category[]=Arrays&sortBy=submissions

// Resource link -- https://leetcode.com/problems/sort-colors/solutions/3034975/easy-solution-three-approach-to-solve-a-problem-dry-run-sorting-counting-dnf-algorithm/

// Video link -- https://youtu.be/oaVa-9wmpns