/*
sliding windows
leetcode 643 easy
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
*/

class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        //set the i = 0, j = k-1 and find the first max
        int i = 0, j = k-1;
        double sum = 0,max;
        for(i = 0; i<=j;i++){
            sum += arr[i];
        }
        max = sum/k;
        //if array size is 1, return max
        if(arr.size() == 1){
            return max;
        }
        i = 0;
        //sliding windows - add next one, deduct last one, append index
        while(j<arr.size()){
            j++;
            sum+=arr[j];
            sum-=arr[i];
            i++;
            if((sum/k)>max){
                max = sum/k;
            }
        }
        return max;
    }   
};