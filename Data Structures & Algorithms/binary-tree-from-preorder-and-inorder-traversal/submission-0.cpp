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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        
        auto recurse = [&](auto &self, int pl, int il, int ir) -> TreeNode *{
            if(il == ir) return nullptr;

            TreeNode *node = new TreeNode(preorder[pl]);

            int middle;
            for(int i = il; i < ir; i++)
                if(inorder[i] == preorder[pl]){middle = i; break;}

            int right = middle - il + pl + 1;
            int left = pl + 1;

            node->left = self(self, left, il, middle);
            node->right = self(self, right, middle+1, ir);

            return node;
        };
    
        return recurse(recurse, 0, 0, inorder.size());
    }
};