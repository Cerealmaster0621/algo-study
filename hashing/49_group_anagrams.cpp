/*
leetcode 49 medium
hashmap <string, vector<string>> for 
key : sorted string , val : push_back
if sorted val is same as key
Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto& s : strs){
            string tmp = s;
            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(s);
        }
        vector<vector<string>> ans (mp.size());
        int i = 0;
        for(const auto& e :mp){
            vector<string> sub = e.second;
            ans[i] = sub;
            i++;
        }
        return ans;
    }
};