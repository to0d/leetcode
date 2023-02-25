#include <lt_help/lt.h>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root == NULL ? 0 : max( maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().maxDepth(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{3,9,20,null,null,15,7}"));
}

// Result 
//
// 2022-11-23: Runtime 23ms 5.33% Memory 19MB 19.51%, https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/848477551/
// 2023-02-18: Runtime 7ms 83% Memory 19MB 19.94%, https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/900124053/
