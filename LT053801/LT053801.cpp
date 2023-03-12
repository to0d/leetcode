#include <lt_help/lt.h>

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        _convertBST(root, sum);
        return root;
    }

    void _convertBST(TreeNode* node, int& sum) {
        if( node == NULL )
            return;
        if( node->right != NULL )
            _convertBST(node->right, sum);
        int val = node->val;
        node->val += sum;
        sum += val;
        if( node->left != NULL )
            _convertBST(node->left, sum);
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    TreeNode* r = Solution().convertBST(root);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{3,0,4,null,2,null,null,1}"));
}

// Result 
//
// 2023-03-11: Runtime 36ms 83.42% Memory 33.5MB 26.78%, https://leetcode.com/problems/convert-bst-to-greater-tree/submissions/913244872/

