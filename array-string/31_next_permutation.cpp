/*
two pointers
leetcode 31 medium
find the next permutation
[5,4,7,5,3,2] -> [5,5,2,3,4,7]
1. find the largest index i that has the arr[i]<arr[i+1]
2. if i is not found, that means number is the largest permutation. reverse the entire order
3. find the largest index  j that is arr[i]<arr[j] and swap arr[i] and arr[j]
4. reverse the entire order from i+1 to end
*/

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int i, j;
        //1. find the i that has the largest arr[i]<arr[i+1]
        for(i = arr.size()-2; i>=0; i--){
            if(arr[i]<arr[i+1]){
                break;
            }
        }
        if(i<0){//if i <0, that means no possible bigger permutation exists, reverse entire order.
            reverse(arr.begin(),arr.end());
        }else{//3. find largest index j that arr[i]<arr[j]
            for(j = arr.size()-1; j>i; j--){
                if(arr[i]<arr[j]){
                    break;
                }
            }
            swap(arr[i],arr[j]);//swap arr[i] and arr[j]
            //4. reverse every order from i+1 ~ end
            reverse(arr.begin()+i+1, arr.end());
        }
    }
};