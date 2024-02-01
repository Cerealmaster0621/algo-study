/*
leetcode 1557 medium
minimum number of vertices to reach all nodes


*/

class Solution {
public:
    unordered_map<int,vector<int>> map;
    unordered_set<int> seen;
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        for(vector<int>& edge : edges){
            map[edge[0]].push_back(edge[1]);
            if(seen.find(edge[1])==seen.end()){
                seen.insert(edge[1]);
            }
        }
        vector<int> ans;
        for(auto& edge : map){
            if(seen.find(edge.first)==seen.end()){
                ans.push_back(edge.first);
            }
        }
        return ans;
    }
};