/*
leetcode 2225 medium
hashmap for losecount + hashset for players list
Example 1:
Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
Output: [[1,2,10],[4,5,7,8]]
Explanation:
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> count_lose;
        unordered_set<int> players;
        vector<vector<int>> ans = {{},{}};
        for(int i =0; i< matches.size();i++){
            count_lose[matches[i][1]]++;
            players.insert(matches[i][0]);
            players.insert(matches[i][1]);
        }
        for(const auto& p : players){
            if(count_lose.find(p)==count_lose.end()){
                ans[0].push_back(p);
            }
            if(count_lose[p] == 1){
                ans[1].push_back(p);
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};