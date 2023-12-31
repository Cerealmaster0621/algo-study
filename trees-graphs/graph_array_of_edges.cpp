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