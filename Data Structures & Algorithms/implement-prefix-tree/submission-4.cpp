class PrefixTree {
    struct Node {
        bool isComplete;
        Node* children[26]; 
        
        Node() {
            isComplete = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

public:
    Node *root;

    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;

        for(auto c: word){
            int index = c - 'a';
            
            if(node->children[index] == nullptr){
                node->children[index] = new Node();
            }

            node = node->children[index];
        }

        node->isComplete = true;
    }
    
    bool search(string word) {
        Node *node = root;

        for(auto c: word){
            int index = c - 'a';

            if(node->children[index] == nullptr) return false;

            node = node->children[index];
        }

        if(!node->isComplete) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;

        for(auto c: prefix){
            int index = c - 'a';

            if(node->children[index] == nullptr) return false;

            node = node->children[index];
        }

        return true;
    }
};
