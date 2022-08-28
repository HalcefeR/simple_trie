#include "../include/trie.h"


TrieNode::TrieNode(const int N) {
    TrieNode::N = N;
    children = new TrieNode*[N];
    for (int child_index = 0; child_index < N; ++child_index)
        children[child_index] = nullptr;
    is_leaf = false;
}

TrieNode::~TrieNode() {
    for (int child_index = 0; child_index < N; ++child_index) {
        if (children[child_index] != nullptr)
            children[child_index]->~TrieNode();
    }
    delete[] children;
}

Trie::Trie(int N, char ALPHABET_FIRST) {
    root = create_node();
    Trie::N = N;
    Trie::ALPHABET_FIRST = ALPHABET_FIRST;
}

Trie::~Trie() {
    remove_node(root);
}

TrieNode* Trie::create_node() {
    return new TrieNode(N);
}

void Trie::remove_node(TrieNode* node) {
    node->~TrieNode();
}

void Trie::insert(const char* word) {
    TrieNode* temp = root;
    for (int char_index = 0; word[char_index] != '\0'; ++char_index) {
        int child_index = word[char_index] - ALPHABET_FIRST;
        if (temp->children[child_index] == nullptr)
            temp->children[child_index] = create_node();
        temp = temp->children[child_index];
    }
    temp->is_leaf = true;
}

void Trie::remove(const char* word, TrieNode* suffix_root) {
    if (word[0] == '\0') return;

    static bool is_exists = true;

    if (!suffix_root) {
        int child_index = word[0] - ALPHABET_FIRST;
        if (root->children[child_index])
            suffix_root = root->children[child_index];
        else return;
    }

    if (word[1]) {
        int child_index = word[1] - ALPHABET_FIRST;
        if (suffix_root->children[child_index])
            remove(++word, suffix_root->children[child_index]);
        else
            is_exists = false;
        if (!is_exists) return;
        suffix_root->children[child_index] = nullptr;
        --word;
    }

    for (int child_index = 0; child_index < N; ++child_index)
        if (suffix_root->children[child_index] != nullptr) return;

    remove_node(suffix_root);
}

TrieNode* Trie::find(const char* word) {
    TrieNode* temp = root;
    for (int char_index = 0; word[char_index] != '\0'; ++char_index) {
        int child_index = word[char_index] - ALPHABET_FIRST;
        if (temp->children[child_index] == nullptr)
            return nullptr;
        temp = temp->children[child_index];
    }

    if (temp != nullptr && temp->is_leaf == true)
        return temp;
    return nullptr;
}
