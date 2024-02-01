/*
leetcode 323 medium
number of connected components in an undirected graph

Dfs approach
make hashmap for undirected graph record,
vector<bool> seen for making sure that dfs doesn't
fall in loop.
loop ENTIRE node from 0 -> n-1, not just neighbor
of the first node.
similar to the number of island problem.

*/

//DFS
class Solution {
public:
    unordered_map<int,vector<int>> map;
    vector<bool> seen;
    int countComponents(int n, vector<vector<int>>& edges) {
        seen = vector(n,false);
        int ans = 0;
        for(vector<int>& edge: edges){
            int x = edge[0], y = edge[1];
            map[x].push_back(y);
            map[y].push_back(x);
        }
        //loop through every nodes instead for(i : map[node])
        //(not just basically neighbor)
        for(int i = 0; i<n; i++){
            if(!seen[i]){
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
    void dfs(int start){
        seen[start] = true;
        for(int& next : map[start]){
            if(!seen[next]){
                dfs(next);
            }
        }
    }
};