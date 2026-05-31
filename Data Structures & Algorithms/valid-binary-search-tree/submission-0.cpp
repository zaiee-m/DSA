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
    bool isValidBST(TreeNode* root) {
        vector<int> order;

        auto validate = [&](auto &self, TreeNode *node){
            if(node == nullptr) return;
            self(self, node->left);
            order.push_back(node->val);
            self(self, node->right);
        };

        validate(validate, root);

        for(int i = 1; i < order.size(); i++){
            if(order[i] <= order[i-1]) return false;
        }
        return true;
    }
};