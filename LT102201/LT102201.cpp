#include <lt_help/lt.h>

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        _sumRootToLeaf(root, 0, &sum);
        return sum;
    }
    
    void _sumRootToLeaf(TreeNode* node, int val, int* sum) {
        val = (val << 1) | node->val;        
        if( node->left == NULL && node->right == NULL )
        {   *sum += val;
            return;
        }
        if( node->left != NULL )
            _sumRootToLeaf(node->left, val, sum);
        if( node->right != NULL )
            _sumRootToLeaf(node->right, val, sum);
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().sumRootToLeaf(root);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test(makeTree("{1,0,1,0,1,0,1}"));
}


// Result 
//
// 2022-12-08: Runtime 30ms 5.50% Memory 16.7MB 50.4%, https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/submissions/856394754/
// 2023-02-18: Runtime 8ms 61.12% Memory 16.8MB 49.49%, https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/submissions/900117333/


