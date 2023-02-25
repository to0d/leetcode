#include <lt_help/lt.h>



class Solution {
public:
    string tree2str(TreeNode* root) {
        static char buf[100000];
        int len = _tree2str(root, buf);
        return string(buf, len);
    }
    
    int _tree2str(TreeNode* node, char* buf)
    {   int len = sprintf(buf, "%d", node->val);
        if( node->left != NULL && node->right == NULL )
        {   buf[len++] = '(';
            len += _tree2str(node->left, buf+len);
            buf[len++] = ')';
        }
        else if( node->left == NULL && node->right != NULL )
        {   buf[len++] = '(';
            buf[len++] = ')';
            buf[len++] = '(';
            len += _tree2str(node->right, buf+len);
            buf[len++] = ')';
        }
        else if( node->left != NULL && node->right != NULL )
        {   buf[len++] = '(';
            len += _tree2str(node->left, buf+len);
            buf[len++] = ')';
            buf[len++] = '(';
            len += _tree2str(node->right, buf+len);
            buf[len++] = ')';
        }
        return len;
    }
};


void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);   
    string r = Solution().tree2str(root);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(makeTree("{1,2,3,4}"));
}


// Result 
//
// 2023-01-10: Runtime 19ms 80.70% Memory 22.9MB 99.91%, https://leetcode.com/problems/construct-string-from-binary-tree/submissions/875475491/



