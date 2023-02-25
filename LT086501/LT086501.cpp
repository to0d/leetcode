#include <lt_help/lt.h>

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        m_maxDeepMap.clear();
        _maxDeepOf(root);
        return _subtreeWithAllDeepest(root);
    }
    
    TreeNode* _subtreeWithAllDeepest(TreeNode* node) {
        int ld = _maxDeepOf(node->left), rd = _maxDeepOf(node->right);
        if( ld == rd )
            return node;
        else if( ld > rd )
            return _subtreeWithAllDeepest(node->left);
        else 
            return _subtreeWithAllDeepest(node->right);
    }
    
    int _maxDeepOf(TreeNode* node){  
        if( node == NULL )
            return 0;
        auto it = m_maxDeepMap.find(node);
        if( it != m_maxDeepMap.end() )
            return it->second;
        
        int ld = _maxDeepOf(node->left), rd = _maxDeepOf(node->right);
        int d  = std::max(ld, rd) + 1;
        m_maxDeepMap[node] = d;
        return d;
    }

    unordered_map<TreeNode*, int> m_maxDeepMap;
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    TreeNode* r = Solution().subtreeWithAllDeepest(root);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{3,5,1,6,2,0,8,null,null,7,4}"));
}

// Result 
//
// 2023-01-13: Runtime 8ms 40.19% Memory 16.6MB 8.16%, https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/submissions/877164786/
// 2023-02-25: Runtime 4ms 73.53% Memory 16.5MB 9.2%, https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/submissions/904428904/




