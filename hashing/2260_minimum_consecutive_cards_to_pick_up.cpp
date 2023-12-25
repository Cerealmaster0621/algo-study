/*
leetcode 2260 medium
hashmap <int, int> for
key : cards[i] val : last found index
and keep update min when it's found twice
Example 1:
Input: cards = [3,4,2,3,4,7]
Output: 4
Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.
*/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> map;
        int mn = 1000000;
        for(int i = 0; i<cards.size(); i++){
            if(map.find(cards[i])!=map.end()){
                mn = min(mn,i-map[cards[i]]+1); //update min val
            }
            map[cards[i]] = i;
        }
        return mn == 1000000?-1:mn;
    }
};