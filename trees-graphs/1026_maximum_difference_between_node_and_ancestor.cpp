/*
leetcode 1026 medium
need recursion outside original function
when we have to compare not just single subtree -
but multiple like this problem(have to compare
every possible differences between parent-child val
, take outside recursion and return it to the
original function.)
One more reason why we use outside recursion - 
we have to take more arguments than original function
this can be used with global variables, but 
this time we make new function with max and min
values and update everytime we traverse.

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
    int recursive(TreeNode* curr, int mx, int mn){
        if(curr == nullptr){
            return mx-mn;
        }
        mx = max(mx, curr->val);
        mn = min(mn, curr->val);
        int left= recursive(curr->left, mx, mn);
        int right = recursive(curr->right, mx, mn);
        return max(left, right);
    }

    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        return recursive(root, root->val, root->val);
    }
};