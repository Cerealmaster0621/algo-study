/*
    leetcode 1926 medium

    bfs start from entrance[r,c]
    make isExit and isValid function
*/

class Solution {
public:
    vector<vector<int>> directions = {{1,0},{0,1}, {-1, 0}, {0,-1}};
    vector<vector<char>> maze;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        this->maze = maze;
        int r = maze.size(), c = maze[0].size(), er = entrance[0], ec = entrance[1];
        queue<vector<int>> q; // r, c, step
        vector<vector<bool>> seen (r, vector<bool>(c,false));

        q.push({er, ec,0});
        seen[er][ec] = true;

        while(!q.empty()){
            vector<int> curr = q.front();
            int row = curr[0], col = curr[1], step = curr[2];
            q.pop();
            seen[row][col] = true;
            for(auto& d : directions){
                int nextRow = d[0]+row, nextCol = d[1]+col;
                if(isExit(nextRow, nextCol) && (row != er || col != ec)){ //exit
                    return step;
                }else if(isValid(nextRow, nextCol) && !seen[nextRow][nextCol]){
                    q.push({nextRow, nextCol, step + 1});
                    seen[nextRow][nextCol] = true;
                }    
            }
        }
        return -1;
    }
    bool isExit(int row, int col){
        return row<0 || row>=maze.size() || col<0 || col>=maze[0].size();
    }
    bool isValid(int row, int col){
        return row >= 0 && row <maze.size()&&col>=0 && col < maze[0].size()&&maze[row][col]=='.';
    }
};