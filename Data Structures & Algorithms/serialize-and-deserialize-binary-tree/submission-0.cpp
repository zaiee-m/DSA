/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *node = q.front(); q.pop();

            if(node == NULL) s += "null ";
            else {
                s += to_string(node->val) + " ";

                q.push(node->left);
                q.push(node->right);
            }
        }

        return s; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);

        string word;
        vector<string> words;

        while(ss >> word) words.push_back(word);

        queue<TreeNode *> q;

        int index = 0;
        if(words[index] == "null") return NULL;
        TreeNode *root = new TreeNode(stoi(words[index]));
        q.push(root);
        index++;

        while(!q.empty()){
            TreeNode *par = q.front(); q.pop();

            if(words[index] == "null") par->left = NULL;
            else{
                TreeNode *nei = new TreeNode(stoi(words[index]));
                par->left = nei;
                q.push(nei);
            }
            index++;

            if(words[index] == "null") par->right = NULL;
            else{
                TreeNode *nei = new TreeNode(stoi(words[index]));
                par->right = nei;
                q.push(nei);
            }
            index++;
        
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));