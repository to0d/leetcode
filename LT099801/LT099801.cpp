#include <lt_help/lt.h>

class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if( root == NULL )
            return new TreeNode(val);
        
        if( root->val < val )
        {   TreeNode* n = new TreeNode(val);
            n->left = root;
            return n;
        }

        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};



void test(TreeNode* root, int val)
{
    cout << "input: val=" << val << ", tree=";
    outputTree(root);
    TreeNode* r = Solution().insertIntoMaxTree(root, val);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{4,1,3,null,null,2}"), 5);
}

// Result 
//
// 2023-01-13: Runtime 8ms 39.33% Memory 13.5MB 65.71%, https://leetcode.com/problems/maximum-binary-tree-ii/submissions/877469526/
// 2023-02-18: Runtime 0ms 100% Memory 13.5MB 66.19%, https://leetcode.com/problems/maximum-binary-tree-ii/submissions/900117822/


