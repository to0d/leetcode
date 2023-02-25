#include <lt_help/lt.h>



class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        m_maxDiff = 0;
        _maxAncestorDiff(root, root, root);
        return m_maxDiff;
    }
    
    void _maxAncestorDiff(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        int update = true;
        
        if( node->val > maxNode->val )
            maxNode = node;
        else if( node->val < minNode->val )
            minNode = node;
        else 
            update = false;
        
        if (update)
            m_maxDiff = std::max(m_maxDiff, (maxNode->val - minNode->val));
        
        if( node->left != NULL )
            _maxAncestorDiff(node->left, minNode, maxNode);
        
        if( node->right != NULL )
            _maxAncestorDiff(node->right, minNode, maxNode);
    }
    
    int m_maxDiff;
};


void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().maxAncestorDiff(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{8,3,10,1,6,null,14,null,null,4,7,13}"));
}

// Result 
//
// 2023-01-30: Runtime 10ms 36.5% Memory 9.6MB 97.19%, https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/submissions/888153738/


