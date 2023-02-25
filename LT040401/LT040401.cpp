#include <lt_help/lt.h>

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if( root != NULL )
            _sumOfLeftLeaves(root, &sum);
        return sum;
    }
    
    void _sumOfLeftLeaves(TreeNode* node, int* sum) {
        if( node->left != NULL )
        {   if( node->left->left == NULL && node->left->right == NULL )
                *sum += node->left->val;
            else
                _sumOfLeftLeaves(node->left, sum);
        }

        if(node->right != NULL )
            _sumOfLeftLeaves(node->right, sum);
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().sumOfLeftLeaves(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{3,9,20,null,null,15,7}"));
}

// Result 
//
// 2022-11-23: Runtime 7ms 39.29% Memory 13.3MB 86.36%, https://leetcode.com/problems/sum-of-left-leaves/submissions/848457159/
// 2023-02-22: Runtime 5ms 42.27% Memory 13.3MB 86.3%, https://leetcode.com/problems/sum-of-left-leaves/submissions/902953695/


