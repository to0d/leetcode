#include <lt_help/lt.h>

struct TrieNode{
    char val;
    bool word;
    TrieNode* child[26];
    TrieNode() : val(0), word(false) { memset(child, 0, sizeof(child)); }
    TrieNode(char c) : val(c), word(false) { memset(child, 0, sizeof(child)); }
};

class Trie {
public:
    Trie() {}
    void insert(string word) { _insert(&m_root, word.c_str(), word.length(), 0); }
    bool search(string word) { return _search(&m_root, word.c_str(), word.length(), 0); }
    bool startsWith(string prefix) { return _startsWith(&m_root, prefix.c_str(), prefix.length(), 0); }
    
private:
    void _insert(TrieNode* node, const char* word, int len, int idx){
        if( idx == len )
        {   node->word = true;
            return;
        }
        char c = word[idx];
        int childIndex = c-'a';
        TrieNode* child = node->child[childIndex];
        if( child == NULL )
        {   child = new TrieNode(c);
            node->child[childIndex] = child;
        }
        _insert(child, word, len, idx+1);
    }
    
    bool _search(TrieNode* node, const char* word, int len, int idx) {
        if( idx == len )
            return node->word;
        char c = word[idx];
        int childIndex = c-'a';
        TrieNode* child = node->child[childIndex];
        if( child == NULL )
            return false;
        return _search(child, word, len, idx+1);
    }
    
    bool _startsWith(TrieNode* node, const char* word, int len, int idx) {
        if( idx == len )
            return true;
        char c = word[idx];
        int childIndex = c-'a';
        TrieNode* child = node->child[childIndex];
        if( child == NULL )
            return false;
        return _startsWith(child, word, len, idx+1);
    }

    TrieNode m_root;
};




int main(void)
{
    cout << "output: done!;" << endl;
}

// Result 
//
// 2023-02-02: Runtime 52ms 94.7% Memory 45.1MB 57.50%, https://leetcode.com/problems/implement-trie-prefix-tree/submissions/890114889/
// 2023-03-12: Runtime 62ms 72.55% Memory 45MB 72.82%, https://leetcode.com/problems/implement-trie-prefix-tree/submissions/913854938/


