#ifndef SIMPLE_TRIE
#define SIMPLE_TRIE

struct TrieNode {
	TrieNode** children;
    bool is_leaf;
    int N;

    TrieNode(const int N);
    ~TrieNode();
};

class Trie {

private:
    TrieNode* root;
    int N;
    char ALPHABET_FIRST;

public:
    Trie(int N = 26, char ALPHABET_FIRST = 'a');
    ~Trie();

public:
    TrieNode* create_node();
    void remove_node(TrieNode* node);

    void insert(const char* word);
    void remove(const char* word, TrieNode* suffix_root = nullptr);

    TrieNode* find(const char* word);

};

#endif /* end of include guard: SIMPLE_TRIE */
