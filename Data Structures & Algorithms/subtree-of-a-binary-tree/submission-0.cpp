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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        auto isSametree = [&](auto &self, TreeNode *root, TreeNode *subRoot) -> bool{
            if(root == nullptr && subRoot == nullptr) return true;
            if(root == nullptr || subRoot == nullptr) return false;
            if(root->val != subRoot->val) return false;
            return self(self, root->left, subRoot->left) && self(self, root->right, subRoot->right);
        };

        auto search = [&](auto &self, TreeNode *root) -> bool{
            if(root == nullptr) return false;
            if(isSametree(isSametree, root, subRoot)) return true;
            return self(self, root->left) || self(self, root->right);
        };

        return search(search, root);
    }
};