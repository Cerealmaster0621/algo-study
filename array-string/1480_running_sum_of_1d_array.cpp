/*
leetcode 1480 easy
prefix sum basic
Example 1:
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
Example 2:
Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& arr) {
        vector<int> prefix = {arr[0]};
        for(int i = 1; i<arr.size();i++){
            prefix.push_back(prefix[i-1]+arr[i]);
        }
        return prefix;
    }
};