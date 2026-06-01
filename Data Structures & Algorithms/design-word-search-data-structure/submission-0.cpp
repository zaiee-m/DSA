class WordDictionary {
    struct Node{
        bool isComplete;
        Node *children[26];

        Node(){
            isComplete = false;
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
    };

public:
    Node *root;

    WordDictionary() {
        root = new Node(); 
    }
    
    void addWord(string word) {
        Node *node = root;
        for(auto c: word){
            int index = c - 'a';

            if(node->children[index] == nullptr)
                node->children[index] = new Node();
            
            node = node->children[index];
        }
        node->isComplete = true;
    }
    
    bool search(string word) {
        auto rsearch = [&](auto &self, string &word, int idx, Node *node) -> bool{

            if (idx == word.size()) {
                return node->isComplete;
            }

            if(word[idx] == '.'){
                for(int i = 0; i < 26; i++){
                    if(node->children[i] != nullptr)
                        if(self(self, word, idx+1, node->children[i])) return true;
                }
            }
            else{
                int chil = word[idx] - 'a';
                if(
                    node->children[chil] != nullptr && 
                    self(self, word ,idx+1 ,node->children[chil])
                ) return true;
            }
            return false;
        };
        
        return rsearch(rsearch, word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */