/*
leetcode 543 easy(medium?)
use helpfunction + global variable
update diameter for largest left + right
helper function return value is just for
updating bigger between left and right
Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
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
    int findLongestPath(TreeNode* root,int& diameter){
        if(root == nullptr){
            return 0;
        }
        int left = findLongestPath(root->left,diameter);
        int right = findLongestPath(root->right,diameter);
        diameter = max(diameter,left+right);
        return max(left, right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        //this is just for updating diameter
        findLongestPath(root,diameter);
        return diameter;
        //return diameter not 
        //findLongestPath function
    }
};

