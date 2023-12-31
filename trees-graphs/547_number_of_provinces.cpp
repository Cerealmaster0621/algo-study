/*
leetcode 547 medium
component problem
1. from adjacency list mark in hashmap entire neighbors on that node.
(make graph less abstract)
2. use dfs function to mark every neighbors in the hashset 
3. iterate hashmap, if key is not in seen, ans++, do dfs

*/

class Solution {
public:
    //
    void dfs(unordered_map<int,vector<int>>& map, unordered_set<int>& set, int node){
        //mark every neighbors in map[node] in set
        for(int i : map[node]){
            if(set.find(i)==set.end()){
                set.insert(i);
                dfs(map,set,i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> map;
        //1.visualize graph
        for(int i = 0; i<isConnected.size();i++){
            for(int j = 0; j<isConnected[i].size();j++){
                if(isConnected[i][j] == 1){
                    map[i].push_back(j);
                    map[j].push_back(i);
                }
            }
        }    
        //2. use dfs for marking every neighbors in set
        unordered_set<int> set;
        int ans = 0;
        for(auto& i : map){
            if(set.find(i.first)==set.end()){
                ans++;
                dfs(map,set,i.first);
            }
        }
        return ans;
    }
};
