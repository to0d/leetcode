#include <lt_help/lt.h>

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return root == NULL || _balanceHeight(root, -1) != -1;
    }

    int _balanceHeight(TreeNode* node, int maxSearchDeep) {
        if( maxSearchDeep == 0 )
            return -1;

        int leftHeight = 0, rightHeight = 0;
        if( node->left != NULL )       
        {   leftHeight = _balanceHeight( node->left, maxSearchDeep-1);
            if( leftHeight == -1 )
                return -1;
        }

        if( maxSearchDeep < 0 )
            maxSearchDeep = leftHeight+2;

        if( node->right != NULL )       
        {   rightHeight = _balanceHeight( node->right, maxSearchDeep-1);
            if( rightHeight == -1)
                return -1;
        }
        
        if( std::abs(rightHeight-leftHeight) > 1 )
            return -1;

        return std::max(leftHeight, rightHeight) + 1;
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    bool r = Solution().isBalanced(root);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(makeTree("{3,9,20,null,null,15,7}"));
}


// Result 
//
// 2022-11-30: Runtime 32ms 12.66% Memory 20.8MB 96.62%, https://leetcode.com/problems/balanced-binary-tree/submissions/852344462/
// 2023-02-18: Runtime 15ms 58.27% Memory 20.8MB 84.86%, https://leetcode.com/problems/balanced-binary-tree/submissions/900125188/


