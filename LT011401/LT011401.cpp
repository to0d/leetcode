#include <lt_help/lt.h>

class Solution {
public:

    void flatten(TreeNode* root) {
        if( root != NULL)
            expend(root);
    }
    
    // return: the tail of list
    TreeNode* expend(TreeNode* root) { 
        if( root->left == NULL )
            return root->right == NULL ? root : expend( root->right ); 
        
        if( root->right == NULL )
        {   root->right = root->left;
            root->left = NULL;
            return expend( root->right );
        }
        
        TreeNode *left = root->left, *right = root->right;
        TreeNode *leftTail = expend(left);
        
        root->left = NULL;
        root->right = left;
        leftTail->right = right;
        return expend(right);
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    Solution().flatten(root);
    cout << "; output: ";
    outputTree(root);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,2,5,3,4,null,6}"));
}


// Result 
//
// 2022-11-22: Runtime 12ms 17.85% Memory 12.8MB 49.27%, https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/848107140/
// 2023-02-22: Runtime 3ms 93.56% Memory 12.8MB 50.15%, https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/902638967/



