/*
Leetcode 189 medium
Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        //idx = abs(arr.size()-(k-i))%arr.size();
        //two pointers
        int sz = arr.size();
        vector<int> res (sz,0);
        k%=sz;
        for(int i = 0; i<sz;i++){
            int x = sz-k+i;
            int idx = abs(x)%sz;
            res[i] = arr[idx];
        }
        for(int i = 0; i<sz;i++){
            arr[i] = res[i];
        }
    }
};