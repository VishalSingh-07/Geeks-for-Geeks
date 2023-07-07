//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Brute Force Approach
// Time complexity -> O(nlogn) + O(2n) and Space -> O(n)

// class Solution {
// public:
//     vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
//          // Code here
//          vector<vector<int>> ans;
//          sort(intervals.begin(),intervals.end());
         
//          for(int i=0;i<intervals.size();i++)
//          {
//              int start=intervals[i][0];
//              int end=intervals[i][1];
             
//              if(!ans.empty() && end<=ans.back()[1])
//              {
//                  continue;
//              }
//              for(int j=i+1;j<intervals.size();j++)
//              {
//                  if(intervals[j][0]<=end)
//                  {
//                      end=max(end,intervals[j][1]);
//                  }
//                  else
//                  {
//                      break;
//                  }
//              }
//              ans.push_back({start,end});
//          }
//          return ans;

//     }
// };

// Optimized Approach
// Time complexity -> O(nlogn) + O(n) and Space -> O(n)
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         vector<vector<int>> ans;
         sort(intervals.begin(),intervals.end());
         
         for(int i=0;i<intervals.size();i++)
         {
             if(ans.empty() || ans.back()[1] < intervals[i][0])
             {
                 ans.push_back(intervals[i]);
             }
             else
             {
                 ans.back()[1]=max(ans.back()[1],intervals[i][1]);
             }
         }
         return ans;

    }
};





//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends

/*
1. Question link -- https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1

2. Solution link -- https://leetcode.com/problems/merge-intervals/solutions/3730445/2-approach-easy-c-solution-brute-force-and-optimized-approach/

3. Video link -- https://youtu.be/IexN60k62jo
*/