#include <lt_help/lt.h>



struct TrieNode{
    char val;
    bool word;
    TrieNode* child[26];
    TrieNode() : val(0), word(false) {
        memset(child, 0, sizeof(child));
    }
    TrieNode(char c) : val(c), word(false) {
        memset(child, 0, sizeof(child));
    }
};

class WordDictionary {
public:
    WordDictionary() {}
    void addWord(string word) { _insert(&m_root, word.c_str(), word.length(), 0); }
    bool search(string word) { return _search(&m_root, word.c_str(), word.length(), 0); }
  
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
        {   return node->word;
        }
        
        char c = word[idx];
        if( c == '.' )
        {   for(int i = 0;i < 26; ++i)
            {   TrieNode* child = node->child[i];
                if( child != NULL )
                {   if( _search(child, word, len, idx+1) )
                        return true;
                }
            }
            return false;
        }
        else
        {   int childIndex = c-'a';
            TrieNode* child = node->child[childIndex];
            if( child == NULL )
            {   return false;
            }

            return _search(child, word, len, idx+1);
        }
    }

    TrieNode m_root;
};


int main(void)
{
    cout << "output: done!;" << endl;
}

// Result 
//
// 2023-02-02: Runtime 877ms 92.88% Memory 558.5MB 68.25%, https://leetcode.com/problems/design-add-and-search-words-data-structure/submissions/890121816/


