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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        int maxLevel = 1;
        int maxSum = INT_MIN; // Initialize with smallest possible integer
        int currLevel = 1;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            int currentLevelSum = 0;

            // Process all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                currentLevelSum += node->val;

                // Add children to queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Check if this level's sum is the highest we've seen
            // strictly '>' ensures we keep the smallest level in case of ties
            if (currentLevelSum > maxSum) {
                maxSum = currentLevelSum;
                maxLevel = currLevel;
            }

            currLevel++;
        }

        return maxLevel;
    }
};
