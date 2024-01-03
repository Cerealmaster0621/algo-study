#include<bits/stdc++.h>

using namespace std;

int main(void){
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    unordered_map<int, vector<int>> map;

    for(auto& edge : edges){
        int x = edge[0];//x
        int y = edge[1];//y

        map[x].push_back(y);
        // if graph is undirected, push y's neighbors
        // also in hashmap
        // map[y].push_back(x); 
    }

    for(auto& [key, val]:map){
        cout<<"node "<<key<<" has neighbors of "<<endl;
        for(int i : val){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

//dfs recursive in graph
void dfs_recursive(int node, unordered_map<int,vector<int>>& graph, unordered_set<int>& seen){
    for(auto neighbor : graph[node]){
        if(!seen[neighbor]){
            seen.insert(neighbor);
            dfs_recursive(neighbor, graph, seen);
        }
    }
}


//dfs iterative in graph
void dfs_iterative(int node, unordered_map<int,vector<int>>& graph,unordered_set<int>& seen){
    stack<int> stack;
    stack.push(node);

    while(!stack.empty()){
        int node = stack.top();
        stack.pop();
        for(auto neighbor : graph[node]){
            if(!seen[neighbor]){
                seen.insert(neighbor);
                stack.push(neighbor);
            }
        }
    }
}