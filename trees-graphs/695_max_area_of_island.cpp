/*
leetcode 695 medium
max area of Island

Dfs approach
use stack(iterative) way of dfs for updating maxans
grid graph problems like this doesn't require
hashmap for recording every possible neighbors, but instead, we have
to iterate entire graph.

iterate over rows and cols, do dfs if grid[i][j] == 1 and haven't visited.



*/

//DFS
class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<bool>> seen;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    int r, c;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        r = grid.size(), c = grid[0].size();
        seen = vector(r,vector<bool>(c,false));
        int ans = 0;
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == 1 && seen[i][j] == false){
                    ans = max(ans, dfs(i,j));
                }
            }
        }
        return ans;
    }
    int dfs(int initR, int initC){
        int ans = 1;
        stack<pair<int,int>> stack;
        stack.push({initR, initC});
        seen[initR][initC] = true;
        while(!stack.empty()){
            int row = stack.top().first, col = stack.top().second;
            stack.pop();
            for(vector<int>& direction : directions){
                int nextRow = row + direction[0], nextCol = col + direction[1];
                if(isValid(nextRow,nextCol)&&!seen[nextRow][nextCol]){
                    seen[nextRow][nextCol] = true;
                    ans++;
                    stack.push({nextRow,nextCol});
                }
            }
        }
        return ans;
    }
    bool isValid(int row, int col){
        return 0<=row&&row<r&&0<=col&&col<c&&grid[row][col] ==1;
    }
};