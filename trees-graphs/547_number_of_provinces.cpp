/*
leetcode 547 medium
component problem
Adjacency list need modification for solving problem
with hashmap etc

1. from adjacency list mark in hashmap entire neighbors on that node.
(make graph less abstract)
2. use dfs function to mark every neighbors in the hashset 
3. iterate hashmap, if key is not in seen, ans++, do dfs

*/

#include<bits/stdc++.h>

class Solution {
public:
    unordered_map<int,vector<int>> map;
    unordered_map<int> set;
    int findCircleNum(vector<vector<int>>& arr) {
        for(int i = 0; i<arr.size();i++){
            for(int j = i+1; j<arr[i].size();j++){
                if(arr[i][j] == 1){
                    map[i].push_back(j);
                    map[j].push_back(i);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<arr.size();i++){
            if(set.find(i)==set.end()){
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
    void dfs(int index){
        set.insert(index);
        for(int i : map[index]){
            if(set.find(i) == set.end()){
                dfs(i);
            }
        }
    }
};
