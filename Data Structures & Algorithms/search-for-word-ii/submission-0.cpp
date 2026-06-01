class Solution {
    class Trie{
    public:
        struct Node{
            bool isComplete;
            Node * children[26];

            Node(){
                isComplete = false;
                for(int i = 0; i < 26; i++)
                    children[i] = nullptr;
            }
        };

        Node *root;

        Trie(){
            root = new Node();
        }

        void insert(string word){
            Node *node = root;
            for(auto c: word){
                int idx = c - 'a';
                if(node->children[idx] == nullptr)
                    node->children[idx] = new Node();
                
                node = node->children[idx];
            }
            node->isComplete = true;
        }
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie dict = Trie();
        Trie::Node *root = dict.root;
        for(auto word: words) dict.insert(word);

        vector<string> validwords;

        int dirs[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        int rows = board.size(), cols = board[0].size();

        auto backtrack = [&](auto &self, Trie::Node *node, int x, int y, string &current) -> void{
            char temp = board[x][y];
            int idx = temp -'a';

            if(node->children[idx] == nullptr) return;
            node = node->children[idx];
            
            current += temp;
            if(node->isComplete) {
                validwords.push_back(current);
                node->isComplete = false;
            }
            board[x][y] = '#';
            
            for(auto dir: dirs){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(
                    nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                    board[nx][ny] != '#'
                ){
                    self(self, node, nx, ny, current);
                }
            }

            current.pop_back();
            board[x][y] = temp;
        }; 

        string s;
        for(int i = 0; i < rows; i++) 
            for(int j = 0; j < cols; j++ )backtrack(backtrack, root, i, j, s);
        return validwords;
    }
};