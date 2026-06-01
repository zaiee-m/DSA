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
    int maxPathSum(TreeNode* root) {
        
        int maxPathSum = INT_MIN;

        auto recurse = [&](auto &self, TreeNode *node){
            if(node == NULL) return 0;

            int left = self(self, node->left);
            int right = self(self, node->right);

            maxPathSum = max(maxPathSum, left+right+node->val);

            int path = max(left, right) + node->val;
            if(path > 0) return path;
            return 0;
        };

        recurse(recurse, root);

        return maxPathSum;
    }
};