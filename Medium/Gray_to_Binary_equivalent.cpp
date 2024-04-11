/*
Gray to Binary equivalent

Given an integer number n, which is a decimal representation of Gray Code. Find the binary equivalent of the Gray Code & return the decimal representation of the binary equivalent.

 

Note: Please visit here to learn How Gray Code is generated.

Example 1:

Input: 
n = 4
Output: 
7
Explanation:
Given 4, its gray code =  110.
Binary equivalent of the gray code 110 is 100.
Return 7 representing gray code 100.


Example 2:

Input: 
n = 15
Output: 
10
Explanation:
Given 15 representing gray code 1000.
Binary equivalent of gray code 1000 is 1111.
Return 10 representing gray code 1111 
ie binary 1010.


Your Task: 
You don't need to read input or print anything. Your task is to complete the function grayToBinary() which accepts an integer n as an input parameter and returns decimal representation of the binary equivalent of the given gray code.

Expected Time Complexity: O(log (n)).
Expected Auxiliary Space: O(1).

Constraints:
0 <= n <= 108
*/
/*
Steps for generating Gray Code:



1. Start by representing the given decimal number in binary form.
2. Begin with the leftmost bit (the most significant bit) of the binary representation.
3. Copy this leftmost bit directly into the corresponding position of the Gray code.
4. For each subsequent bit:
      a. Take the XOR operation between the last generated bit in the gray code and the bit immediately to its right in the binary representation of the given number.
      b. Place the result in the corresponding position of the Gray code.
5. Continue this process until you have processed all the bits in the binary representation.
6. The resulting binary representation obtained from the XOR operations represents the Gray code equivalent of the given decimal number.


Example: 
n = 10  —> binary representation = 1010

Gray code: 1 _ _ _  [ from point 3 ]
Gray code: 1 1 _ _  [ from point 4  ( 1^0 = 1 ) ]
Gray code: 1 1 0 _  [ from point 4  ( 1^1 = 0 ) ]
Gray code: 1 1 0 0  [ from point 4  ( 0^0 = 0 ) ]

1100 —> 12 (in decimal)

*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// Brute Force Approach
// Time complexity -> O(logn) and Space -> O(logn)
/*
1. First Convert n to Binary code
2. Convert Binary Code to Gray Code 
3. Convert Gray Code to Decimal 

return decimal value
*/
class Solution{
    private:
    // Converting binary Code to Gray Code
    string binaryCodeToGrayCode(string binaryCode){
        string grayCode="";
        grayCode+=binaryCode[0];
        for(int i=1;i<binaryCode.size();i++){
          grayCode+=to_string((grayCode.back()-'0')^(binaryCode[i]-'0'));
        }
        return grayCode;
    }
    
    // Converting Gray Code to Decimal 
    int grayCodeToDecimal(string binaryCode){
        int decimal=0;
        int x=0;
        for(int i=binaryCode.size()-1;i>=0;i--){
            decimal+=pow(2,x++)*(binaryCode[i]-'0');
        }
        return decimal;
    }
    
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        // Convert n to Binary Code
        if(n==0){
            return 0;
        }
        string binaryCode="";
        while(n>0){
            binaryCode=to_string(n%2)+binaryCode;
            n/=2;
        }
        string grayCode=binaryCodeToGrayCode(binaryCode);
        return grayCodeToDecimal(grayCode);
        
    }
};


// Optimized Approach
// Time complexity -> O(logn) and Space -> O(1)
class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        // Convert n to Binary Code
        int num=0;
        while(n>0){
            num^=n;
            n>>=1;
        }
        return num;
        
    }
};






//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends

/*
1. Question link -- https://www.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/1

2. Video Link -- https://youtu.be/qXs1oBRb-J0?feature=shared
*/