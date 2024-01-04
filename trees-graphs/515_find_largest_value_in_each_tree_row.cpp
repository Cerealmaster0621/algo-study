/*
leetcode 515 medium
bfs + updating max value for each depth iteration

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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        int mx;
        while(!q.empty()){
            int n = q.size();//size of current depth
            mx = INT_MIN;
            while(n--){//use while loop instead for
                TreeNode* node = q.front();
                //every iteration of node, update max
                mx = max(mx,node->val);
                q.pop();
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
            }
            //after iteration of depth, append ans
            ans.push_back(mx);
        }
        return ans;
    }
};