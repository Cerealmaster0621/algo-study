/*
leetcode 239 hard
using deque since we need approaches from
front and back.
first iterate k length from array and push
in to deque. make sure that deque.front()
always shows the biggest value AND store it 
in indicies instead of value
while loop inside sliding window 
Example 1
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deque;
        vector<int> ans;
        for(int i =0 ; i<k ;i ++){
            if(deque.empty()){
                deque.push_back(i);
                continue;
            }
            while(!deque.empty()&&nums[deque.back()]<nums[i]){
                deque.pop_back();
            }
            deque.push_back(i);
        }
        ans.push_back(nums[deque.front()]);
        int right = k, left = 1;
        while(right!=nums.size()){
            if(deque.front()<left){
                deque.pop_front();
            }
            while(!deque.empty()&&nums[deque.back()]<nums[right]){
                deque.pop_back();
            }
            deque.push_back(right);
            ans.push_back(nums[deque.front()]);
            ++left;
            ++right;
        }
        return ans;
    }
};