#include <lt_help/lt.h>



class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return _isUnivalTree(root, root->val);
    }
    
    bool _isUnivalTree(TreeNode* node, int val) {
        return (node == NULL) 
            || (node->val == val 
                    && _isUnivalTree(node->left, val) 
                    &&  _isUnivalTree(node->right, val));
    }
};


void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    bool r = Solution().isUnivalTree(root);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test(makeTree("{1,1,1,1,1,null,1}"));
}


// Result 
//
// 2022-12-07: Runtime 3ms 63.91% Memory 9.8MB 81.12%, https://leetcode.com/problems/univalued-binary-tree/submissions/856153073/


