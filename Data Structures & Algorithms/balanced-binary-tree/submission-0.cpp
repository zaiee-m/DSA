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
    bool isBalanced(TreeNode* root) {
        
        auto height = [&](auto &height, TreeNode *root){
            if(root == nullptr) return pair<bool,int>{true, 0};

            auto left = height(height, root->left);
            auto right = height(height, root->right);

            int leftHeight = left.second, rightHeight = right.second;
            int nodeHeight = max(leftHeight, rightHeight) + 1;

            if(!left.first || !right.first) return pair<bool,int>{false, nodeHeight};
            else{
                if(leftHeight + 1 == rightHeight || leftHeight == rightHeight + 1 || leftHeight == rightHeight)
                    return pair<bool,int>{true, nodeHeight};
                else return pair<bool,int>{false, nodeHeight};
            }
        };

        return height(height, root).first;
    }
};