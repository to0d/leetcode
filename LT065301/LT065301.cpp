#include <lt_help/lt.h>

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        return _findTarget(root, root, k);        
    }
    
    bool _findTarget(TreeNode* root, TreeNode* node, int k) {
        if( k != node->val*2 )
        {   TreeNode* node2 = _find(root, k - node->val);
            if(node2 != NULL && node2 != node)
                return true;
        }

        if (node->left != NULL && _findTarget(root, node->left, k))
            return true;
        
        if (node->right != NULL && _findTarget(root, node->right, k))
            return true;

        return false;
    }
    
    TreeNode* _find(TreeNode* node, int k) {     
        if( node->val == k )
            return node;
        
        if( k < node->val && node->left != NULL)
            return _find(node->left, k);
        
        if( k > node->val && node->right != NULL)
            return _find(node->right, k);
        
        return NULL;
    }
};



void test(TreeNode* root, int k)
{
    cout << "input: k=" << k << ", root=";
    outputTree(root);   
    bool r = Solution().findTarget(root, k);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{2,1,3}"), 4);
}

// Result 
//
// 2022-11-25: Runtime 72ms 15.86% Memory 36.1MB 98.45%, https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/849549447/
// 2023-02-24: Runtime 35ms 89.91% Memory 36.1MB 96.76%, https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/904182246/


