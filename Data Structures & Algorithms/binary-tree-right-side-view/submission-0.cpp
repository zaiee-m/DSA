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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> q;
        if(root != nullptr) q.push(root);
        vector<int> rightSideView;
        
        while(!q.empty()){
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++){
                TreeNode *curr = q.front(); q.pop();
                if(i == 0) rightSideView.push_back(curr->val);
                if(curr->right != nullptr) q.push(curr->right);
                if(curr->left != nullptr) q.push(curr->left);
            }
        }
        return rightSideView;
    }
};