//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;
 
string to_upper(string in);
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		cout << to_upper(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends



string to_upper(string str){
    
    transform(str.begin(), str.end(),str.begin(),::toupper);
    return str;
    //code
    
}

// Question Link -- https://practice.geeksforgeeks.org/problems/lower-case-to-upper-case3410/1?page=1&difficulty[]=-2&status[]=solved&category[]=Strings&sortBy=submissions