#include <lt_help/lt.h>




class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if( root == NULL )
            return NULL;
        if( root->val < low )
            return trimBST(root->right, low, high);
        if( root->val > high )
            return trimBST(root->left, low, high);
        if( root->left != NULL )
            root->left = trimBST(root->left, low, high);
        if( root->right != NULL )
            root->right = trimBST(root->right, low, high);
        return root;
    }
};



void test(TreeNode* root, int low, int high)
{
    cout << "input: low=" << low << ", high=" << high << ", tree=";
    outputTree(root);
    TreeNode* r = Solution().trimBST(root, low, high);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{3,0,4,null,2,null,null,1}"), 1, 3);
}

// Result 
//
// 2023-01-12: Runtime 8ms 97.31% Memory 23.9MB 76.51%, https://leetcode.com/problems/trim-a-binary-search-tree/submissions/876833218/


