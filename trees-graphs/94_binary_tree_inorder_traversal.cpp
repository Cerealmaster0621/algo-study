/*
leetcode 94 easy
inorder basic.
declare global variable ans and return 
Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]
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
    vector<int> ans = {};
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return ans;
        }
        inorderTraversal(root->left);
        //inorder here
        ans.push_back(root->val);
        inorderTraversal(root->right);
        return ans;
    }
};

//dividing seperate function is faster
class Solution {
public:
    vector<int> ans;
    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
        return ;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};