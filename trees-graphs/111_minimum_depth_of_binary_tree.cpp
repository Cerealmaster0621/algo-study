/*
leetcode 111 easy
recursive/iterative. check recursive<->iterative
pseudo code in readme.md
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
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

//recursive
/*
Algorithm
1.We will use the dfs method with root as an argument.
2.The base condition of the recursion would be for the NULL node, in which case we should return 0.
3.If the left child of root is NULL, then we should return 1 + minimum depth for the right child of the root node, which is 1 + dfs(root.right).
4.If the right child of root is NULL, then we should return 1 + minimum depth for the left child of the root node, which is 1 + dfs(root.left).
5.If both child are non-null, then return 1 + min(dfs(root.left), dfs(root.right)).
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr){
            return 1+minDepth(root->right);
        }else if(root->right == nullptr){
            return 1+minDepth(root->left);
        }
        return 1+min(minDepth(root->left), minDepth(root->right));
    }
};

//iterative
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        if((root->left== nullptr)&&(root->right == nullptr)) return 1;
        stack<pair<TreeNode*, int>> stack;
        stack.push(pair(root, 1));
        int mn;
        while(!stack.empty()){
            auto[node, val] = stack.top();
            stack.pop();
            if((node != root)&&(node->left==nullptr)&&(node->right==nullptr)){
                mn = min(mn, val);
            }
            if(node -> left != nullptr){
                stack.push(pair(node->left,val+1));
            }
            if(node -> right != nullptr){
                stack.push(pair(node->right,val+1));
            }
        }
        return mn;
    }
};