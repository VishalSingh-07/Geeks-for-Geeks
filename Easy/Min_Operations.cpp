//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*
If we see this carefully, we can make a and b equal in maximum 2 moves.

case 1 : We can set
    move 1: a = a&b
    move 2: b = a&b
    
    total moves = 2

case 2:
    move 1: a=a&b 
    
    if a&b and b are equal then number of moves  =1

case 3: 
    
    if a and b are equal then number of moves = 1
*/

// Time complexity --> O(1) and Space --> O(1)
class Solution {
  public:
    int solve(int a, int b) {
        // code here
        
        if(a==b)
        {
            return 0;
        }
        int x=a&b;
        if(a==x || b==x)
        {
            return 1;
        }
        return 2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/5a7e1a52f1b7796238f9efea4c6fda389f26c327/1