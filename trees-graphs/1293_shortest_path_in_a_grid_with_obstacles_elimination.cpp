/*
    leetcode 1293 hard
    bfs modification
    set q {row, col, step, remaining obstacles}
    set 2d seen {remaining obstacles}
    inside next direction loop check
    isValid(), inside 
    - remaining obstacles > 0 && grid[r][c] == 1
    - grid[r][c] == 0
*/

class Solution {
public:
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    int sizeRow , sizeCol;
    int shortestPath(vector<vector<int>>& grid, int k) {
        int r = grid.size(), c = grid[0].size();
        this->sizeRow = r;
        this->sizeCol = c;
        vector<vector<int>> seen (r, vector<int>(c, -1));
        queue<vector<int>> q;
        q.push({0,0,0,k}); // row, col, steps, remaining obs
        seen[0][0] = k;
        while(!q.empty()){
            vector<int> curr = q.front();
            int row = curr[0], col = curr[1], step = curr[2], rm = curr[3];
            if(row == r-1 && col == c-1) return step;
            q.pop();
            for(auto& d : directions){
                int nextRow = row + d[0], nextCol = col + d[1];
                if(isValid(nextRow, nextCol,seen, rm)){
                    if(rm > 0 && grid[nextRow][nextCol] == 1){
                        q.push({nextRow, nextCol, step+1, rm-1});
                        seen[nextRow][nextCol] = rm-1;
                    }else if(grid[nextRow][nextCol] == 0){
                        q.push({nextRow, nextCol, step + 1, rm});
                        seen[nextRow][nextCol] = rm;
                    }
                }
            }
        }
        return -1;
    }

    bool isValid (int row, int col, vector<vector<int>>& seen, int rm){
        return row >= 0 && row < sizeRow && col >= 0 && col < sizeCol && seen[row][col] < rm;
    }
};