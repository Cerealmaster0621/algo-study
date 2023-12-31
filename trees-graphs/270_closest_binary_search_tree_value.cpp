/*
leetcode 270 easy
DONT COMPARE deducted value with min,
such as if(min(smth, smth2) == smth2)
just do it like if(smth > smth2){
}elseif(smth == smth2)
there are always edge cases with min()comparison


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, double target){
        if(root == nullptr){
            return INT_MAX;
        }
        stack<TreeNode*> stack;
        stack.push(root);
        int ans = INT_MAX;
        double mn = INT_MAX;
        while(!stack.empty()){
            TreeNode* node = stack.top();
            stack.pop();
            if(node->left != nullptr){
                stack.push(node->left);
            }
            if(node->right != nullptr){
                stack.push(node->right);
            }
            if(mn > abs(target-node->val)){
                mn = abs(target-node->val);
                ans = node->val;
            }else if(mn == abs(target-node->val)){
                ans = min(ans, node->val);
            }
        }
        return ans;
    }

    int closestValue(TreeNode* root, double target) {
        return dfs(root, target);
    }
};