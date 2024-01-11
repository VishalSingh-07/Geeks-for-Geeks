//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


// Brute Force Approach
// Time complexity -> O(logn) and Space -> O(1)
class Solution{
  public:
    string convertToRoman(int n) {
        // code here
        int numbers[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string symbols[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        
        int i=12;
        string ans="";
        while(n>0)
        {
            int div=n/numbers[i];
            n=n%numbers[i];
            
            while(div>0)
            {
                ans+=symbols[i];
                div--;
            }
            i--;
        }
        return ans;
        
    }
};



// Optimized Approach
// Time complexity -> O(1) and Space -> O(1)
class Solution{
  public:
    string convertToRoman(int n) {
        // code here
        string thousands[]={"","M","MM","MMM"};
        string hundreds[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string tens[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string ones[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        
        string ans="";
        ans+=thousands[n/1000];
        ans+=hundreds[(n%1000)/100];
        ans+=tens[(n%100)/10];
        ans+=ones[n%10];
        
        return ans;
        
    }
};



//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		Solution ob;
    	cout << ob.convertToRoman(N) << endl;
	}
	return 0;
}
// } Driver Code Ends



/*
1. Question Link -- https://www.geeksforgeeks.org/problems/convert-to-roman-no/1

2. Solution Link -- https://leetcode.com/problems/integer-to-roman/solutions/4547454/2-approach-easy-c-solution-brute-force-and-optimized-approach/
*/