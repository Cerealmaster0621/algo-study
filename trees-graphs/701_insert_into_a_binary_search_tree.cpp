/*
Leetcode 701 medium
BST + DFS
Recursive

breakpoint - when root is nullptr
middle - if rootval < right, right is recursive right
else left is recursive left
base return - root(keep moves to right or left.
will return final adequate place)

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //breakpoint
        if(root == nullptr){
            return new TreeNode(val);
        }
        //nodeval< val?
        if(root->val < val){
            root->right = insertIntoBST(root->right, val);
        }else{
            root->left = insertIntoBST(root->left, val);
        }
        //final return
        return root;
    }
};