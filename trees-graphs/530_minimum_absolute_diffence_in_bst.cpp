/*
leetcode 530 easy
when traversing BST,
using INORDER DFS
means it is traversing with the order.
store it in arr and compare one by one

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
    void dfs(TreeNode* root, vector<int>& arr){
        if(root == 0){
            return;
        }
        dfs(root->left,arr);
        arr.push_back(root->val);
        dfs(root->right,arr);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> arr;
        dfs(root,arr);
        int ans = INT_MAX;
        for(int i = 1; i<arr.size();i++){
            ans = min(ans, abs(arr[i-1]-arr[i]));
        }
        return ans;
    }
};