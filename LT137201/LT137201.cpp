#include <lt_help/lt.h>

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        m_leftMap.clear();
        m_rightMap.clear();
        int _max = INT_MIN;
        _longestZigZag(root, _max);
        return _max - 1;
    }
    
    void _longestZigZag(TreeNode* node, int& _max) {
        if( node == NULL )
            return;
        int lv = _zigZagOf(node, true);
        int rv = _zigZagOf(node, false);
        if( lv > _max )
            _max = lv;
        if( rv > _max )
            _max = rv;
        _longestZigZag(node->left, _max);
        _longestZigZag(node->right, _max);
    }
    
    int _zigZagOf(TreeNode* node, bool left) {
        if( node == NULL )
            return 0;
        
        unordered_map<TreeNode*, int>& _map = left ? m_leftMap : m_rightMap;
        auto it = _map.find(node);
        if( it != _map.end() )
            return it->second;
        
        TreeNode* child = left ? node->left : node->right;
        int zz = _zigZagOf(child, !left) + 1;
        _map[node] = zz;
        return zz;
    }
    
    unordered_map<TreeNode*, int> m_leftMap;
    unordered_map<TreeNode*, int> m_rightMap;    
};


void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().longestZigZag(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1}"));
}

// Result 
//
// 2023-01-14: Runtime 379ms 19.21% Memory 147MB 12.67%, https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/submissions/877785734/
// 2023-02-25: Runtime 382ms 15.67% Memory 146.8MB 11.61%, https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/submissions/904426823/


