//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
// class Solution{
//     public:
//     int longestUniqueSubsttr(string s){
//         //code
//         int n=s.size();
//         if(n==0 || n==1)
//         {
//             return n;
//         }
//         int longestStreak=0;
//         for(int i=0;i<n;i++)
//         {
//             unordered_set<char> st;
//             for(int j=i;j<n;j++)
//             {
//                 if(st.find(s[j])!=st.end())
//                 {
//                     break;
//                 }
//                 st.insert(s[j]);
//                 longestStreak=max(longestStreak,j-i+1);
//             }
//         }
//         return longestStreak;
        
//     }
// };

// Above code give timit limit Exceeded due to high time complexity


// Better Approach
// Time complexity -> O(2n) and Space -> O(n)
// class Solution{
//     public:
//     int longestUniqueSubsttr(string s){
//         //code
//         int n=s.size();
//         if(n==0 || n==1)
//         {
//             return n;
//         }
//         int left=0;
//         int right=0;
//         int longestStreak=0;
//         unordered_set<char> st;
//         while(right<n)
//         {
//             if(st.find(s[right])!=st.end())
//             {
//                 while(left<right && st.find(s[right]) != st.end())
//                 {
//                     st.erase(s[left]);
//                     left++;
//                 }
//             }
//             st.insert(s[right]);
//             longestStreak=max(longestStreak,right-left+1);
//             right++;
//         }
//         return longestStreak;
        
//     }
// };

// Above code give timit limit Exceeded due to high time complexity

// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        int n=s.size();
        if(n==0 || n==1)
        {
            return n;
        }
        int left=0;
        int right=0;
        int longestStreak=0;
        vector<int> mpp(256,-1);
        while(right<n)
        {
            if(mpp[s[right]]!=-1)
            {
                left=max(mpp[s[right]]+1,left);
            }
            mpp[s[right]]=right;
            longestStreak=max(longestStreak,right-left+1);
            right++;
        }
        return longestStreak;
        
    }
};





//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*
1. Question link -- https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1

2. Solution link -- https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/3847862/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/

3. Video link -- https://youtu.be/qtVh-XEpsJo
*/
