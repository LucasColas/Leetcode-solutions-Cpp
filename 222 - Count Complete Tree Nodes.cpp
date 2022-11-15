
/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
https://leetcode.com/problems/count-complete-tree-nodes/
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
    int get_height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int height_l = get_height(root->left);
        int height_r = get_height(root->right);
        return (height_l > height_r ? height_l+1: height_r+1);
    }
    
    int count_last_level(TreeNode* root, int h, int level) {
        if (!root) {
            return 0;
        }
        
        if (!root->left && !root->right && h == level) {
            return 1;
        }
         level++;
        return count_last_level(root->left, h,level) + count_last_level(root->right, h,level);
        
    }
    
    
    int countNodes(TreeNode* root) {
        
        
        int height = get_height(root);
        int count = count_last_level(root, height, 1);
        //cout << height;
        //cout << (pow(2,height-1)-1);
        //cout << " " << count;
        return (pow(2,height-1)-1) + count;
        
    }
};
