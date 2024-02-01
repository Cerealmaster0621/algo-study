/*
leetcode 1971 easy
Find if path exists in graph

dfs solution
use hashmap map for undirected graph
use vector<bool> seen for making sure that 
dfs doesn't fall in loop.

inside the dfs function, 
break point  - if (start == destination) return true;
loop inside the map[start] and make another condition
if(dfs(neighbor, destionation)) instead of 
return dfs(neighbor, destination)
this is bc if it returns dfs directly, if the previous
function returns false, it will immediately
return false instead of exploring every possible 
paths. 

*/

//DFS
class Solution {
public:
    unordered_map<int,vector<int>> map;
    vector<bool> seen;

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        seen = vector(n, false);
        for(vector<int>& edge : edges){
            int x = edge[0], y = edge[1];
            map[x].push_back(y);
            map[y].push_back(x);
        }
        seen[source] = true;
        return dfs(source, destination);
    }

    bool dfs(int start, int destination){
        if(start == destination){
            return true;
        }
        for(int& neighbor : map[start]){
            if(!seen[neighbor]){
                seen[neighbor] = true;
                // 바로 dfs return 하지 말고 neighbor를 탐색 한 후에 return true.
                // 처음 코드 return dfs(neighbor, destination);
                // revised version
                if(dfs(neighbor, destination)){
                    return true;
                }
            }
        }
        return false;
    }
};