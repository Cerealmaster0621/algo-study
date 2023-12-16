/*
sliding window
leetcode 209 medium
Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int length = 2, sum = 0, i=0, j=1;
        for(int k = 0; k<arr.size();k++){
            if(arr[k]>=target) return 1;
        }
        //loop it until length is equal to arr.size()
        while(length <= arr.size()){
            //j<arr.size()
            sum = 0;
            i = 0;
            j = length-1;
            for(int k = i;k<=j;k++){
                sum+=arr[k];
            }//2
            if(length == arr.size() && sum < target) break;
            while(j<arr.size()){
                if(sum >= target) return length;
                j++;
                sum+=arr[j];
                sum-=arr[i];
                i++;
            }
            length++;
        }
        //if the length == arr.size() && sum <target
        return 0;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int start = 0, sum = 0, minLength = INT_MAX;
        for (int end = 0; end < arr.size(); end++) {
            sum += arr[end];
            while (sum >= target) {
                minLength = min(minLength, end - start + 1);
                sum -= arr[start];
                start++;
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};





