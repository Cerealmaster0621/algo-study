/*
2270 leetcode medium
Number of ways to split Array
Example 1:
Input: nums = [10,4,-8,7]
Output: 2
Explanation: 
There are three ways of splitting nums into two non-empty parts:
- Split nums at index 0. Then, the first part is [10], and its sum is 10. The second part is [4,-8,7], and its sum is 3. Since 10 >= 3, i = 0 is a valid split.
- Split nums at index 1. Then, the first part is [10,4], and its sum is 14. The second part is [-8,7], and its sum is -1. Since 14 >= -1, i = 1 is a valid split.
- Split nums at index 2. Then, the first part is [10,4,-8], and its sum is 6. The second part is [7], and its sum is 7. Since 6 < 7, i = 2 is not a valid split.
Thus, the number of valid splits in nums is 2.

*/

vector<bool> answerQueries(vector<int>& arr, vector<vector<int>>& queries, int limit) {
    vector<int> prefix = {arr[0]};
    int sz = queries.size();
    vector<int> ans (sz);
    //prefix has added.
    for(int i = 1 ;i <arr.size();i++){
        int new_var = arr[i] + prefix[i-1];
        prefix.push_back(new_var);
    } 
    for(auto& k : queries){
        int i = k[0], j = k[1];
        bool flg = limit > prefix[j]-prefix[i]+arr[i];
        ans.push_back(flg);
    }
    return ans;
}

//using prefix array
class Solution {
public:
    int waysToSplitArray(vector<int>& arr) {
        vector<long int> prefix = {arr[0]};
        int end = arr.size()-1;
        //added prefix for sum.
        for(int i = 1; i<arr.size();i++){
            long int new_var = arr[i] + prefix[i-1];
            prefix.push_back(new_var);
        }
        int cnt = 0;
        //sum i to j -> prefix[j]-prefix[i]+arr[i]
        for(int i = 0; i<arr.size()-1;i++){
            long int right = prefix[end]-prefix[i+1]+arr[i+1];//i+1 to end
            long int left = prefix[i]-prefix[0]+arr[0];//0 to i
            if(left>=right) cnt++;
        }
        return cnt;
    }
};

//not necessarily prefix
class Solution {
public:
    int waysToSplitArray(vector<int>& arr) {
        long int sum = 0;
        long int tmp = 0;
        int cnt = 0;
        for(int i = 0; i< arr.size();i++){
            sum+= arr[i];
        }
        for(int i = 0; i<arr.size()-1;i++){
            tmp+=arr[i];
            if(tmp>=(sum-tmp)) cnt++;
        }
        return cnt;
    }
};