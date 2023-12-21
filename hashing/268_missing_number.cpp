/*
leetcode 268 easy
hashset but can also use gaussian sum 
Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
*/
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        unordered_set<int> set;
        int n = arr.size();
        for(int i = 0; i<n;i++){
            set.insert(arr[i]);
        }
        for(int i = 0; i<=n; i++){
            if(set.find(i)==set.end()){
                return i;
            }
        }
        return -1;
    }
};