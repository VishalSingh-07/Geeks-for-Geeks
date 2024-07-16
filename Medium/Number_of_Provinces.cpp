/*
Number of Provinces

Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:

Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.



Example 2:
Input:
[
 [1, 1],
 [1, 1]
]

Output :
1

Your Task:  
You don't need to read input or print anything. Your task is to complete the function numProvinces() which takes an integer V and an adjacency matrix adj(as a 2d vector) as input and returns the number of provinces. adj[i][j] = 1, if nodes i and j are connected and adj[i][j] = 0, if not connected.


Expected Time Complexity: O(V2)
Expected Auxiliary Space: O(V)

Constraints:
- 1 ≤ V ≤ 500
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


// Optimzed Approach [Using Adjacency List]
// Time complexity -> O(n) + O(V+2E) and Space -> O(n)
// Where O(N) is for outer loop and inner loop runs in total a single DFS over entire graph, and we know DFS takes a time of O(V+2E). 
class Solution {
    private:
    void dfs(int node, vector<int> adjList[], vector<int> &visited){
        visited[node]=1;
        for(auto it: adjList[node]){
            if(!visited[it]){
                dfs(it, adjList,visited);
            }
        }
    } 
    public:
    int numProvinces(vector<vector<int>> adj, int V) {

        vector<int> adjList[V];

        // Creating Adjacency List
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> visited(V,0);
        int province=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                province++;
                dfs(i,adjList,visited);
            }
        }
        return province;
    }
};


// Optimzed Approach [Using Adjacency Matrix]
// Time complexity -> O(n) + O(V+2E) and Space -> O(n)
// Where O(n) is for outer loop and inner loop runs in total a single DFS over entire graph, and we know DFS takes a time of O(V+2E). 
class Solution {
    private:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &visited){
        int v=adj.size();
        visited[node]=1;
        for(int i=0;i<v;i++){
            if(!visited[i] && adj[node][i]){
                dfs(i,adj,visited);
            }
        }
    } 
    public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> visited(V,0);
        int province=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                province++;
                dfs(i,adj,visited);
            }
        }
        return province;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*
1. Question link -- https://www.geeksforgeeks.org/problems/number-of-provinces/1

2. Solution link -- https://leetcode.com/problems/number-of-provinces/solutions/5486845/optimized-approach-with-explanation-easy-c-solution-striver-solution

3. Video link -- https://youtu.be/ACzkVtewUYA?si=MWzGtvBP8Zq6Ggq_
*/