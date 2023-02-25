#include <lt_help/lt.h>




class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if( root == NULL )
            return new TreeNode(val);
        
        if( root->val < val )
            root->right = insertIntoBST(root->right, val);
        else 
            root->left  = insertIntoBST(root->left, val);
        
        return root;
    }
};



void test(TreeNode* root, int val)
{
    cout << "input: val=" << val << ", tree=";
    outputTree(root);
    TreeNode* r = Solution().insertIntoBST(root, val);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{4,2,7,1,3}"), 5);
}

// Result 
//
// 2023-01-12: Runtime 92ms 87.81% Memory 56.9MB 85.34%, https://leetcode.com/problems/insert-into-a-binary-search-tree/submissions/876837115/


