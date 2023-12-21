/*
leetcode 1 easy
use hashmap [arr[i], i]
and find if hashmap[target-arr[i]] exists.
return hash_map[target-arr[i]],i
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,int> hash_map;
        for(int i = 0; i<arr.size();i++){
            int diff = target-arr[i];
            if(hash_map.find(diff)!=hash_map.end()){
                return {hash_map[diff],i};
            }
            hash_map[arr[i]] = i;
        }
        return {-1,-1};
    }
};