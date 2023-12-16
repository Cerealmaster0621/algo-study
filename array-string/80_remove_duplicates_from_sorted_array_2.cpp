/*
two pointers
Leetcode 80 Medium
Example 1:
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i = 0, j = 1, cnt = 0;
        if(arr.size() == 1) return 1; //if v size 1 -> return 1
        while(j<arr.size()){
            //when arr[i] == arr[j] cnt++, if cnt==1 arr[++i] = arr[j++] else j++
            if(arr[i] == arr[j]){
                cnt++;
                if(cnt == 1){
                    i++;
                    arr[i] = arr[j];
                    j++;
                }else{
                    j++;
                }
            //else arr[++i] = arr[j++] , cnt = 0
            }else{
                i++;
                arr[i] = arr[j];
                j++;
                cnt = 0;
            }
        }
        return i+1;
    }
};