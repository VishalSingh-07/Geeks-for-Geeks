//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function vallate for C++

// Brute Force Approach
// Time complexity -> O(n) and Space --> O(1)
// class Solution {
// public:
//     vector<int> factorial(int n){
//         // code here
//         int fact=1;
//         for(int i=1;i<=n;i++)
//         {
//             fact=fact*i;
//         }
//         return {fact};
       
//     }
// };

// Above code is not working due to given constraint  1<=N<=1000 (factorial of 10^3 is overflow the integer)

// Optimized Approach
// Time complexity --> O(n^2) and Space --> O(1)
/*
Explanation:
let 5!=5x4x3x2x1=120;
120 we can write in three block of array
i.e. {1,2,0}
to achive this start array with length 1 i.e. ans={1}.
now start multiplying each element of that array.
let i=1 to 5.
i.e val=ans[0]*i=1 i.e. val[0]=val%10={1}. and carry=0;
val=ans[0]*2=1*2=2 therefor ans[0]=val%10={2}. and carry=0;
val=ans[0]*3=2*3=6 hance ans[0]=val%10={6}. and carry=0;
val=ans[0]*4=6*4=24 here val>10 hence 
ans[0]=val%10=4 and carry=24/10 = 2 
so it enter into while(carry!=0)
then it push_back ans.push_back(2%10), so it push back ans.push_back(2);
there for ans={4,2}
and carry=2/10; --> 0 then we move out from while loop

val=ans[0]*5=4*5=20 hance ans[0]=20%10=0.
ans={0,2}
because we have one more element hance carry=20/10 ==2
val=ans[1]*5+carray=10+2=12 and 
ans[1]=val%10=2 
carry=12/10 --> carry=1
ans={0,2}
so it enter into while(carry!=0)
then it push_back ans.push_back(1%10), so it push back ans.push_back(1);
there for ans={0,2,1}
as you can see we have all the element but in reverse order just we need to reverse the array
ans={1,2,0}
*/
class Solution {
public:
    vector<int> factorial(int n){
        // code here
        vector<int> ans;
        ans.push_back(1);
        for(int i=2;i<=n;i++)
        {
            int carry=0;
            for(int j=0;j<ans.size();j++)
            {
                int val=ans[j]*i+carry;
                ans[j]=val%10; // storing ones part
                carry=val/10; // storing the carry of val part
            }
            while(carry!=0)
            {
                ans.push_back(carry%10);
                carry=carry/10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

// Question link -- https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

// Video link --https://www.youtube.com/live/Rv4uNb2QX2w?feature=share