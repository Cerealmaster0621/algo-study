/*
leetcode 98 medium
If the tree is valid BST,
DFS inorder means it will perform orderly
(i-1 will always be smaller than ith node value)

or

set min and max, 
do recursive dfs and check everytime if 
root-> val is smaller than min or greater than max,
return false if this case.
left = recursive(root->left, min, root->val)
and right vice versa.
this idea came from that left is always have to 
smaller than parent value in bst.

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
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
    void dfs(TreeNode* root, vector<int>& ans){
        if(root == nullptr){
            return;
        }
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }

    bool isValidBST(TreeNode* root) {
        if(root==nullptr){
            return false;
        }
        vector<int> arr; 
        dfs(root, arr);
        for(int i = 1; i<arr.size();i++){
            if(arr[i-1]>=arr[i]){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool dfs(TreeNode* root, long min, long max){
        if(root == nullptr){//null tree is technically bst
            return true;
        }
        //check every recursion
        if(root->val <= min || root->val >= max){
            return false;
        }
        int left=  dfs(root->left, min, root->val);
        int right = dfs(root->right, root->val, max);
        return left && right; //when they all return true
    }

    bool isValidBST(TreeNode* root) {
        //long min and long max bc of constraints
        return dfs(TreeNode* root, LONG_MIN,LONG_MAX);
    }
};