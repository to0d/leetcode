#include <lt_help/lt.h>

class Solution {
public:
    void flatten(TreeNode* root) {
        if( root != NULL)
            expend(root);
    }

    TreeNode* expend(TreeNode* node) {  // return: the tail of list
        if( node->left == NULL )
            return node->right == NULL ? node : expend( node->right ); 

        if( node->right == NULL )
        {   node->right = node->left;
            node->left = NULL;
            return expend( node->right );
        }

        TreeNode *left = node->left, *right = node->right;
        TreeNode *leftTail = expend(left);
        
        node->left = NULL;
        node->right = left;
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
// 2023-03-13: Runtime 3ms 93.4% Memory 12.8MB 49.17%, https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/913904713/



