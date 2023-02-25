#include <lt_help/lt.h>




class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        static char buf[1024] = {0};
        vector<string> res; 
        
        if( root != NULL )
            generate(root, buf, 0, res);
        
        return res;
    }
    
    void generate(TreeNode* node, char* buf, int len, vector<string>& res)
    {
        if( len > 0 )
        {
            buf[len++] = '-';
            buf[len++] = '>';
        }
        
        len += sprintf(buf+len, "%d", node->val);
        if( node->left == NULL && node->right == NULL )
        {
            res.push_back(string(buf, buf+len));
            return;
        }
        
        if( node->left != NULL )
            generate(node->left, buf, len, res);
        
        if( node->right != NULL )
            generate(node->right, buf, len, res);
    }
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

