/*
    leetcode 1046 easy
    basic heap manipulation
    initialize heap with pq(stones.begin(),stones,end());

*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq (stones.begin(),stones.end());
        while(!pq.empty()){
            if(pq.size() == 1){
                return pq.top();
            }
                int y = pq.top();
                pq.pop();
                int x = pq.top();
                pq.pop();
                if(y!=x) pq.push(y-x);
        }
        return 0;
    }
};