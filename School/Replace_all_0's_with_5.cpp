//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
// Driver program to test above function

// } Driver Code Ends
class Solution{
  public:
    /*you are required to complete this method*/
    int reverse(int r)
    {
        int temp=r;
        int remainder,sum=0;
        while(temp>0)
        {
            remainder=temp%10;
            sum=sum*10+remainder;
            temp=temp/10;
            
            
        }
        return sum;
    }
    int convertFive(int n)
    {
        //Your code here
        int temp=n;
        int rem,r=0;
        while(temp>0)
        {
            rem=temp%10;
            if(rem==0)
            {
                rem=5;
            }
            r=r*10+rem;
            
            temp=temp/10;
            
        }
        return reverse(r);
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	Solution obj;
    	cout<<obj.convertFive(n)<<endl;
    }
}
// } Driver Code Ends

// Question Link -- https://practice.geeksforgeeks.org/problems/replace-all-0-with-5-in-an-input-integer/1?page=2&difficulty[]=-2&status[]=solved&sortBy=submissions