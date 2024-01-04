/*
leetcode 199 medium
bfs adaptation
use deque instead queue for last value 
Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<int> ans;
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            int n = q.size();
            TreeNode* tmp = q.back();
            ans.push_back(tmp->val);
            for(int i = 0;i<n;i++){
                TreeNode* node = q.front();
                q.pop_front();
                if(node->left != nullptr){
                    q.push_back(node->left);
                }
                if(node->right != nullptr){
                    q.push_back(node->right);
                }
            }
        }
        return ans;
    }
};