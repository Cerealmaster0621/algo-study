/*
leetcode 2352 medium
hashmap <string, vector<int>> for
key : stringify row/col, 
val : [0] - row count, [1] - col count
return i.second[0]*i.second[1] or 0
Example 1
Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
*/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,vector<int>> count;
        string stro, stco;
        int cnt = 0;
        for(int i = 0; i<grid.size();i++){
            stro = "";
            stco = "";
            for(int j = 0; j <grid[i].size();j++){
                stro+=to_string(grid[i][j])+",";
                stco+=to_string(grid[j][i])+",";
            }
            if(count.find(stro)==count.end()){
                count[stro] = vector<int>(2,0);
            }
            if(count.find(stco)==count.end()){
                count[stco] = vector<int>(2,0);
            }
            count[stro][0]++;
            count[stco][1]++;
        }
        for(const auto& i : count){
            cnt += (i.second[0]>0 && i.second[1]>0) ? i.second[0]*i.second[1]:0;
        }
        return cnt;
    }
};