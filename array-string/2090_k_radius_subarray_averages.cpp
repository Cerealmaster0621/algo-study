/*
leetcode 2090 medium
sliding window + prefix sum?
Example 1:
Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
Output: [-1,-1,-1,5,4,4,-1,-1,-1]
Explanation:
- avg[0], avg[1], and avg[2] are -1 because there are less than k elements before each index.
- The sum of the subarray centered at index 3 with radius 3 is: 7 + 4 + 3 + 9 + 1 + 8 + 5 = 37.
  Using integer division, avg[3] = 37 / 7 = 5.
- For the subarray centered at index 4, avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4.
- For the subarray centered at index 5, avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4.
- avg[6], avg[7], and avg[8] are -1 because there are less than k elements after each index.
Example 3:
Input: nums = [8], k = 100000
Output: [-1]
Explanation: 
- avg[0] is -1 because there are less than k elements before and after index 0.
*/

class Solution {
public:
    vector<int> getAverages(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = arr.size();
        vector<int> avgs (n,-1);
        if(n <= 2*k) return avgs;
        long int first_sum = 0;
        for(int i = 0; i<=2*k ; i++){
            first_sum += arr[i];
        }
        avgs[k] = first_sum/(2*k+1);
        for (int i = k+1; i<=n-k-1; i++){
            first_sum-=arr[i-k-1];
            first_sum+=arr[i+k];
            avgs[i] = first_sum/(2*k+1);
        }
        return avgs;
    }
};