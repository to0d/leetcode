#include <lt_help/lt.h>

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if( root1 == NULL ) return root2;
        if( root2 == NULL ) return root1;

        root1->val  += root2->val;
        root1->left  = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};



void test(TreeNode* root1, TreeNode* root2)
{
    cout << "input: root1=";
    outputTree(root1);
    cout << ", root2=";
    outputTree(root2);
    cout << "; output: ";
    TreeNode* r = Solution().mergeTrees(root1, root2);
    outputTree(r);
    cout << ";" << endl;
}

int main(void)
{
    test(makeTree("{1,3,2,5}"), makeTree("{2,1,3,null,4,null,7}"));
}

// Result 
//
// 2022-11-25: Runtime 86ms 5.88% Memory 32.4MB 67.14%, https://leetcode.com/problems/merge-two-binary-trees/submissions/849542670/
// 2023-02-24: Runtime 39ms 75.18% Memory 32.3MB 91.27%, https://leetcode.com/problems/merge-two-binary-trees/submissions/904180762/
