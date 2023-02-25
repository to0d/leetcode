#include <lt_help/lt.h>

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if( root == NULL )
            return 0;        
        
        if( root->val < low )
            return rangeSumBST(root->right, low, high);
        
        if( root->val == low )
            return root->val + rangeSumBST(root->right, low, high);
        
        if( root->val == high )
            return root->val + rangeSumBST(root->left, low, high);
        
        if( root->val > high )
            return rangeSumBST(root->left, low, high);
        
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};



void test(TreeNode* root, int low, int high)
{
    cout << "input: low=" << low << ", high=" << high << ", root=";
    outputTree(root);
    int r = Solution().rangeSumBST(root, low, high);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test(makeTree("{10,5,15,3,7,null,18}"), 7, 15);
}


// Result 
//
// 2022-12-06: Runtime 183ms 15.12% Memory 64.6MB 65.94%, https://leetcode.com/problems/range-sum-of-bst/submissions/855598313/
// 2023-02-24: Runtime 131ms 76% Memory 64.7MB 66.66%, https://leetcode.com/problems/range-sum-of-bst/submissions/904198655/


