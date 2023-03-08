#include <lt_help/lt.h>

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        static char buf[1024] = {0};
        m_res.clear();
        _binaryTreePaths(root, buf, 0);
        return m_res;
    }
    
    void _binaryTreePaths(TreeNode* node, char* buf, int len) {
        len += sprintf(buf+len, "->%d", node->val);
        if( node->left == NULL && node->right == NULL )
        {   m_res.push_back(string(buf+2, len-2));
            return;
        }
        if( node->left != NULL )
            _binaryTreePaths(node->left, buf, len);
        if( node->right != NULL )
            _binaryTreePaths(node->right, buf, len);
    }

    vector<string> m_res;
};

    
    
void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    vector<string> r = Solution().binaryTreePaths(root);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,2,3,null,5}"));
}

// Result 
//
// 2022-11-23: Runtime 0ms 100% Memory 12.3MB 94.42%, https://leetcode.com/problems/binary-tree-paths/submissions/848461150/
// 2023-03-08: Runtime 3ms 82.19% Memory 12.3MB 94.14%, https://leetcode.com/problems/binary-tree-paths/submissions/911521675/

