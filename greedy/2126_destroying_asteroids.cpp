/*
leetcode 2126 medium
greedy intuition:
sort the array, choose the best choices (remember
all the values added until the last, see if
prevsum >= current)
*/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        //3 5 9 19 21 [3 8 17 36 21]
        // 4 4 9 23 [4 8 17 23]
        long ans = mass;
        for(int i = 0; i<asteroids.size(); i++){
            if(asteroids[i] <= ans){
                ans+=asteroids[i];
            }else{
                return false;
            }
        }
        return true;
    }
};