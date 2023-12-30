/*
leetcode 226 easy
using bfs but you don't need to populate q.size()
for iterate inside depth because we don't really have
anything to do with those. 
for example, if we have tree like
        1
    2       3
4       5,6     7
and the problem expected
        1
    3       2
5       4,7     6
then it is inside depth inversion, but this cases
        1
    3       2
7       6,5     4
they required entire depth to be inverted so
just swap in the first loop level.
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            //this time not populating n but directly populate treenode from q
            TreeNode* node = q.front();
            q.pop();
            if(node!= nullptr){//left or right could be nullptr
                swap(node->left->val, node->right->val);
            }
            if(node->left != nullptr){
                q.push(node->left);
            }
            if(node->right != nullptr){
                q.push(node->right);
            }
        }
        return root;
    } 
};