/*
leetcode 2294 medium
two pointer + greedy
you have to sort array first for two pointer.
left and right starts from 0, iterate until
right reaches to the end of the array.
if arr[r]-arr[l]<=k, increament r
else, counter ++ (new subsequences needed).
move left to the right
*/

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        //12356     5 4 2
        //1 2 3     3 2 3
        sort(nums.begin(), nums.end());
        int left = 0, right = 0, ans = 1;
        while(right < nums.size()){
            if(nums[right]-nums[left]<=k){
                right++;
            }else{
                ans++;
                left = right;
            }
        }
        return ans;
    }
};