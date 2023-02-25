#include <lt_help/lt.h>

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head, *tail;
        _increasingBST(root, &head, &tail);
        return head;
    }
    
    void _increasingBST(TreeNode* node, TreeNode** head, TreeNode** tail) {
        if( node->left != NULL )
        {   TreeNode* leftHead = NULL, *leftTail = NULL;
            _increasingBST(node->left, &leftHead, &leftTail);
            *head = leftHead;
            *tail = leftTail;
            (*tail)->right = node;
            *tail = node;
            node->left = NULL;
        }
        else
        {   *head = node;
            *tail = node;
        }

        if( node->right != NULL )
        {   TreeNode* rightHead = NULL, *rightTail = NULL;
            _increasingBST(node->right, &rightHead, &rightTail);
            (*tail)->right = rightHead;
            *tail = rightTail;
        }
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    TreeNode* r = Solution().increasingBST(root);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}

int main(void)
{   
    test(makeTree("{5,1,7}"));
}


// Result 
//
// 2022-12-03: Runtime 4ms 35.98% Memory 7.7MB 86.36%, https://leetcode.com/problems/increasing-order-search-tree/submissions/853696042/
// 2023-02-18: Runtime 0ms 100% Memory 7.6MB 86.47%, https://leetcode.com/problems/increasing-order-search-tree/submissions/900120898/




