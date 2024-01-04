/*
leetcode 112 easy
recursion/iterative two ways
usually recursion is slower.
think what we should do in the leaf node
in this specific question, we have to keep update 
targetSum by deducting the root->left or right val.
Example 1
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
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
//recursive
class Solution { // Time complexity - O(n), Spac complexity - O(N) in general,
// O(logN) when tree is completely balanced.
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        //basecase
        if(root == nullptr){
            return 0;
        }
        targetSum -= root->val;
        if(((root->left == nullptr) &&(root->right == nullptr))){
            return targetSum == 0;
        } // return false just in case, but final return could be true
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right , targetSum);
    }
}; // do recursive and return true when single case returns true.

/*
iterative methods
pair current node pointer with targetsum - sum until current
*/
class Solution{
public:
    bool hasPathSum(TreeNode* root, int targetSum){
        if(root == nullptr){
            return false;
        }
        stack<pair<TreeNode*, int>> stack;
        stack.push(pair(root, targetSum - root->val));
        while(!stack.empty()){
            auto[node, val] = stack.top();
            stack.pop();
            if((node->left == nullptr)&&(node->right == nullptr) && val == 0){
                return true;
            }
            if(node->left != nullptr){
                stack.push(pair(node->left, val - node->left->val));
            }
            if(node->right != nullptr){
                stack.push(pair(node->right, val - node->right->val));
            }
        }
        return false;
    }
};

