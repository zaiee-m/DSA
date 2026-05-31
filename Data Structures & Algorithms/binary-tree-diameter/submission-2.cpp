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
    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxPath = INT_MIN;

        auto recursiveDiameter = [&](auto &recursiveDiameter, TreeNode* root){
            if(root == nullptr) return 0;
            int left = recursiveDiameter(recursiveDiameter, root->left);
            int right = recursiveDiameter(recursiveDiameter, root->right);

            maxPath = max(maxPath, left+right);

            return max(left, right)+1;
        };

        recursiveDiameter(recursiveDiameter, root);

        return maxPath;
    }
};
