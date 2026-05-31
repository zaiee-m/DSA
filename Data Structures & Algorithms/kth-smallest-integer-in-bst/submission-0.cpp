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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nonDecreasing;

        auto inorder = [&nonDecreasing](auto &self, TreeNode* node){
            if(node == nullptr) return;
            self(self, node->left);
            nonDecreasing.push_back(node->val);
            self(self, node->right);
        };

        inorder(inorder, root);
        return nonDecreasing[k-1]; 
    }
};