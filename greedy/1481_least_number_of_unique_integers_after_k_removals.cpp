/*
leetcode 1481 medium
hashmap for frequencies + vector descending order
for comparison.
use while if the condition of the problem is 
max/min until k. (k-- , k>0 etc if the problem
is about how many times and maximum is k times, 
use k-- and if max sum of something is k, use
while k>0). 
*/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        /*
            1. frequencies with hashmap
            2. vec<int> cnt on descending order 
            3. comp cnt.back() and k, if k >= val k-=val else break;
            4. iterate loop unless k > 0
        */
        unordered_map<int, int> map; // val : cnt
        for(int i : arr){
            map[i]++;
        }
        vector<int> cnt;
        for(auto i : map){ // 2 
            cnt.push_back(i.second);
        }
        sort(cnt.begin(), cnt.end(), greater<int>());
        while(k>0){ // 3 2 1 1 
            int val = cnt.back();
            if(val <= k){
                k-=val;
                cnt.pop_back();
            }else{
                break;
            }
        }
        return cnt.size();
    }
};