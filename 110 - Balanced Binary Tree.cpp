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
    int Depth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left_depth = 1 + Depth(root->left);
        int right_depth = 1 + Depth(root->right);
        return max(left_depth, right_depth);
    }
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        int left_depth = Depth(root->left);
        int right_depth = Depth(root->right);

        if (abs(left_depth - right_depth) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
        

        
    }
};
