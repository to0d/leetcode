#include <lt_help/lt.h>



class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        m_x = x, m_y = y, m_deep_x = -1, m_deep_y = -1;
        m_parent_x = NULL, m_parent_y = NULL;
        _find(NULL, root, 0);
        if( m_deep_x == -1 || m_deep_y == -1 )
            return false; 
        //cout << "xd="<< m_deep_x << ", yd="<< m_deep_y  
        //     << ", xp=" << ((m_parent_x == NULL) ? -1 : m_parent_x->val)
        //     << ", yp=" << ((m_parent_y == NULL) ? -1 : m_parent_y->val) << endl;
        return (m_deep_x == m_deep_y) && m_parent_x != m_parent_y;
    }
    
    void _find(TreeNode* parent, TreeNode* node, int deep)
    {   
        if(node->val == m_x )
        {   m_deep_x    = deep;
            m_parent_x  = parent;
        }
        else if(node->val == m_y)
        {   m_deep_y    = deep;
            m_parent_y  = parent;
        }

        if( m_deep_x != -1 && m_deep_y != -1 )
            return;
        
        if(node->left != NULL)
            _find(node, node->left, deep+1);
        
        if( m_deep_x != -1 && m_deep_y != -1 )
            return;
        
        if(node->right != NULL)
            _find(node, node->right, deep+1);
    }
    
    int m_x;
    int m_y;
    int m_deep_x;
    int m_deep_y;
    TreeNode* m_parent_x;
    TreeNode* m_parent_y;
};


void test(TreeNode* root, int x, int y)
{
    cout << "input: x=" << x << ", y=" << y << ", tree=";
    outputTree(root);
    bool r = Solution().isCousins(root, x, y);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test(makeTree("{1,2,3,4}"), 4, 3);
}


// Result 
//
// 2022-12-07: Runtime 0ms 100% Memory 10.9MB 78.10%, https://leetcode.com/problems/cousins-in-binary-tree/submissions/855887564/


