#include <lt_help/lt.h>

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        m_maxCount = 0, m_lastCount = 0, m_lastVal = 0;
        m_res.clear();
        _inorderTraversal(root);
        return m_res;
    }
    
    void _inorderTraversal(TreeNode* node) {
        if(node == NULL)
            return;
        
        _inorderTraversal(node->left);
        
        if( node->val == m_lastVal )
            ++m_lastCount;
        else 
        {   m_lastVal   = node->val;
            m_lastCount = 1;
        }

        if( m_lastCount > m_maxCount )
        {   m_res.clear();
            m_res.push_back(m_lastVal);
            m_maxCount = m_lastCount;
        }
        else if( m_lastCount == m_maxCount )
            m_res.push_back(m_lastVal);

        _inorderTraversal(node->right);
    }

    int m_maxCount;
    int m_lastCount;
    int m_lastVal;
    vector<int> m_res;
};
 


void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    vector<int> r = Solution().findMode(root);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test(makeTree("{1,null,2,2}"));
}


// Result 
//
// 2023-01-09: Runtime 19ms 86.6% Memory 24MB 84.88%, https://leetcode.com/problems/find-mode-in-binary-search-tree/submissions/874802106/
// 2023-03-09: Runtime 11ms 98.84% Memory 24MB 86.82%, https://leetcode.com/problems/find-mode-in-binary-search-tree/submissions/911548868/

