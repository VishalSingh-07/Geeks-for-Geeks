//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void printPat(int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
    printPat(n);
    cout<<endl;
	}
}
// } Driver Code Ends


/*You are required to complete this method*/
void printPat(int n)
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=n;i>0;i--)
        {
            for(j=0;j<n-k;j++)
            {
                cout<<i<<" ";
            }
        }
        cout<<" $";
    }
}

// Question Link --- https://practice.geeksforgeeks.org/problems/print-the-pattern-set-1/1?page=1&difficulty[]=-2&status[]=solved&sortBy=submissions