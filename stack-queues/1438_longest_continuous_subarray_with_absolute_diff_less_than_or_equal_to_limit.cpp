/*
leetcode 1438 medium
use deque when push/pop from front/back both 
necessary.
sliding window + two deque for decreasing/inc-
reasing order. compare front value of decreasing
and increasing, update answer with length(right-left+1)
Example 1
Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> increasing;
        deque<int> decreasing;
        int left = 0, ans = -1;
        for(int right = 0; right<nums.size();right++){
            while(!increasing.empty()&& increasing.back()>nums[right]){
                increasing.pop_back();
            }
            while(!decreasing.empty()&& decreasing.back()<nums[right]){
                decreasing.pop_back();
            }
            increasing.push_back(nums[right]);
            decreasing.push_back(nums[right]);
            while(decreasing.front()-increasing.front()>limit){
                if(nums[left]==decreasing.front()){
                    decreasing.pop_front();
                }
                if(nums[left]==increasing.front()){
                    increasing.pop_front();
                }
                ++left;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};