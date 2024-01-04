/*
leetcode medium 103
keep the node->left right logic but instead
change the order of indexing inner vector using
int idx = cnt%2==0?i:n-1-i
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int n = q.size();
            vector<int> depth(n);
            for(int i = 0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                int idx = cnt%2==0?i:n-1-i;
                depth[idx] = node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(depth);
            cnt++;
        }
        return ans;
    }
};