/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        auto search = [&](auto &self, TreeNode *root, TreeNode *p, TreeNode *q) -> TreeNode *{
            if(root == nullptr) return nullptr;
            int valRoot = root->val, valq = q->val, valp = p->val;
            if(valRoot > valq && valRoot > valp){
                return self(self, root->left, p, q);
            }
            else if(valRoot < valq && valRoot < valp){
                return self(self, root->right, p, q);
            }
            else{
                return root;
            }
        };

        return search(search, root, p, q);
    }
};