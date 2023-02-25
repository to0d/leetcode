#include <lt_help/lt.h>




class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if( root == NULL )
            return NULL;
        
        if( root->left != NULL )
            root->left = pruneTree(root->left);
        
        if( root->right != NULL )
            root->right = pruneTree(root->right);
        
        if( root->left != NULL || root->right != NULL || root->val == 1)
            return root;
        
        return NULL;
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    TreeNode* r = Solution().pruneTree(root);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,null,0,0,1}"));
}

// Result 
//
// 2023-01-12: Runtime 3ms 63.24% Memory 8.8MB 75.16%, https://leetcode.com/problems/binary-tree-pruning/submissions/876841576/


