//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}
// } Driver Code Ends

// A iterative function to reverse a number
int reverse(int temp)
{
    int ans=0;
    while(temp>0)
    {
        int rem=temp%10;
        ans=ans*10+rem;
        temp=temp/10;
    }
    return ans;
}
/*you are required to complete this method*/
int convertFive(int n) {
    // Your code here
    // if num is 0 return 5
    if(n==0)
    {
        return 5;
    }
    else
    {
        int temp=0;
        
        while (n>0)
        {
            int digit = n%10;
            // if digit is 0, make it 5
            if(digit==0)
            {
                digit=5;
            }
            
            temp=temp*10+digit;
            n=n/10;
        }
        // call the function reverse the number by passing temp
        return reverse(temp);
    }
    
}

// Question Link -- https://practice.geeksforgeeks.org/problems/replace-all-0s-with-5/1?page=1&difficulty[]=-1&status[]=solved&category[]=Arrays&sortBy=submissions