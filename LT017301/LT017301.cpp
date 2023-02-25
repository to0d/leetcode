#include <lt_help/lt.h>

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        _move(root);
    }
    
    int next() {
        TreeNode* node = m_path.back();
        m_path.pop_back();
        int val = node->val;
        _move(node->right);
        return val;
    }       

    bool hasNext() {
        return m_path.size() != 0;
    }
    
    void _move(TreeNode* node)
    {   while( node != NULL )
        {   m_path.push_back(node);
            if( node->left != NULL )
                node = node->left;
            else
                node = NULL;
        }
    }
    
    vector<TreeNode*> m_path;
};



int main(void)
{
    cout << "output: done!" << endl;
}

// Result 
//
// 2023-01-04: Runtime 84ms 5.28% Memory 24MB 91.44%, https://leetcode.com/problems/binary-search-tree-iterator/submissions/870871960/
// 2023-02-22: Runtime 31ms 65.8% Memory 24.1MB 91.23%, https://leetcode.com/problems/binary-search-tree-iterator/submissions/902643892/



