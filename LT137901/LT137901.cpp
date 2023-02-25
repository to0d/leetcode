#include <lt_help/lt.h>



class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* rst = NULL;
        if( original == target )
            rst = cloned;
        if( rst == NULL && original->left != NULL )
            rst = getTargetCopy(original->left, cloned->left, target);
        if( rst == NULL && original->right != NULL )
            rst = getTargetCopy(original->right, cloned->right, target);
        return rst;
    }
};


int main(void)
{   
    cout << "output: done!" << endl;
}


// Result 
//
// 2022-12-13: Runtime 569ms 50.99% Memory 164MB 19.48%, https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/submissions/858945906/


