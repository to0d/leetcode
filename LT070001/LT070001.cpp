#include <lt_help/lt.h>

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if( root == NULL )
            return NULL;
        
        if( root->val == val )
            return root;
        
        TreeNode* node = searchBST(root->left, val);
        if( node != NULL )
            return node; 
        
        return searchBST(root->right, val);
    }
};



void test(TreeNode* root, int val)
{
    cout << "input: val=" << val << ", tree=";
    outputTree(root);
    TreeNode* r = Solution().searchBST(root, val);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}

int main(void)
{   test(makeTree("{4,2,7,1,3}"), 2);
}


// Result 
//
// 2022-12-01: Runtime 94ms 6.77% Memory 34.8MB 71%, https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/852605609/
// 2023-02-24: Runtime 31ms 98.39% Memory 34.8MB 71.18%, https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/904187983/


