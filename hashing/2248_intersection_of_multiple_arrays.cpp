/*
leetcode 2248 easy
basic hashmap count
Example 1:
Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
Output: [3,4]
Explanation: 
The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] = [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].

*/

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> count;
        vector<int> ans;
        for(int i = 0; i<nums.size();i++){
            for(int j = 0; j<nums[i].size();j++){
                count[nums[i][j]]++;
                if(count[nums[i][j]]==nums.size()){
                    ans.push_back(nums[i][j]);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};