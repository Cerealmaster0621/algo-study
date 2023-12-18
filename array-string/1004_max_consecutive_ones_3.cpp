/*
sliding windows
1004 leetcode medium
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int left = 0,cnt = 0,length = 0;
        for(int right = 0; right<arr.size();right++){
            while(cnt>k){
                if(arr[left] == 0){
                    cnt--;
                }
                left++;
            }
            if(arr[right] == 0){
                cnt++;
            }
            if(cnt<=k) length = max(length, right-left+1);
        }
        return length;
    }
};