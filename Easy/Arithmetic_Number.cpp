//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// class Solution{
// public:
//     int inSequence(int A, int B, int C){
//         // code here
//         if(C==0 && A==B)
//         {
//             return 1;
//         }
//         if(C!=0 && (B-A)%C==0 && (B-A)/C>=0)
//         {
//             return 1;
//         }
        
//         return 0;
//     }
// };

class Solution{
public:
    int inSequence(int a, int b, int c){
        // code here
        if(c==0)
        {
            if(a==b)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else 
        {
            if((b-a)/c<0)
            {
                return 0;
            }
            else
            {
                if((b-a)%c==0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1

/*
Video Link --

1.https://youtu.be/NbDvSmubKP8

2. https://youtu.be/TWnrwJslatU

3. https://youtu.be/pJdRJqcq-8M
*/