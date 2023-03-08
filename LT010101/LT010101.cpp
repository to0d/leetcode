#include <lt_help/lt.h>

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode* a, TreeNode* b){
        if( a == NULL )
            return b == NULL;
        if( b == NULL || a->val != b->val )
            return false;
        return isMirror(a->left, b->right) && isMirror(a->right, b->left);
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    bool r = Solution().isSymmetric(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,2,2,3,4,4,3}"));
}

// Result 
//
// 2022-11-23: Runtime 18ms 6.92% Memory 16.3MB 95.89%, https://leetcode.com/problems/symmetric-tree/submissions/848481741/
// 2023-02-22: Runtime 4ms 72.3% Memory 16.4MB 83.76%, https://leetcode.com/problems/symmetric-tree/submissions/902637317/
// 2023-03-08: Runtime 3ms 88.60% Memory 16.4MB 58.69%, https://leetcode.com/problems/symmetric-tree/submissions/911337325/

