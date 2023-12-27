/*
leetcode 739 medium
handling elements in backward order should remind you of a stack.
place the !stack.empty() prior to the stack.empty()
logic.
Vector-stack can be used as stacking index of vector
to approach vector with stacked index.
Example 1
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> stack;
        vector<int> ans (temp.size(),0);
        for(int i = temp.size()-1; i>=0; i--){
            while(!stack.empty()&&temp[stack.top()]<=temp[i]){
                stack.pop();
            }
            if(stack.empty()){
                ans[i] = 0;
                stack.push(i);
                continue;
            }
            if(temp[stack.top()]>temp[i]){
                int dist = stack.top()-i;
                ans[i] = dist;        
            }
            stack.push(i);
        }
        return ans;
    }
};