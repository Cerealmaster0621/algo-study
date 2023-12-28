/*
leetcode 104 easy
finding the maximum depth of the binary tree.
function is returning something -> store recursive in 
variable and return with some logic.
Input: root = [3,9,20,null,null,15,7]
Output: 3
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
//iterative approach using stack - preorder
class Solution{
public:
    int maxDepth(TreeNode* root){
        //base cases
        if(root == nullptr){
            return 0;
        }
        stack<pair<TreeNode*, int>> stack;
        int ans = 0;
        stack.push(pair(root, 1));
        while(!stack.empty()){
            auto[node, depth] = stack.top();
            stack.pop();
            ans = max(ans, depth);
            if(node->left != nullptr){
                stack.push(pair(node->left, depth+1));
            }
            if(node->right != nullptr){
                stack.push(pair(node->right, depth+1));
            }
        }
        return ans;
    }
};


//recursive approach - postorder
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //base cases where root is nullptr
        if(root == nullptr){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        // + 1 because this problem requires.
        return max(left, right) + 1;
    }
};