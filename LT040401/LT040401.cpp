#include <lt_help/lt.h>

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if( root == NULL )
            return 0;
        int sum = 0;
        if( root->left != NULL )
            sum += isLeaf(root->left) ? root->left->val : sumOfLeftLeaves(root->left);
        if( root->right != NULL )
            sum += sumOfLeftLeaves(root->right);
        
        return sum;
    }
    
    bool isLeaf(TreeNode* node) {
        return node->left == NULL && node->right == NULL;
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
// 2023-03-08: Runtime 4ms 67.57% Memory 13.4MB 52.42%, https://leetcode.com/problems/sum-of-left-leaves/submissions/911526645/


