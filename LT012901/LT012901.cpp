#include <lt_help/lt.h>

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return root == NULL ? 0 : getSum(root, 0);
    }
    
    int getSum(TreeNode* node, int val){
        val = val*10 + node->val;
        if( node->left == NULL && node->right == NULL)
            return val;
        
        return (node->left != NULL ? getSum(node->left, val) : 0)
             + (node->right != NULL ? getSum(node->right, val) : 0);
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().sumNumbers(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,2,3}"));
}

// Result 
//
// 2022-11-23: Runtime 8ms 5.56% Memory 9.3MB 53.14%, https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/848487352/
// 2023-02-22: Runtime 4ms 29.8% Memory 9.1MB 87.71%, https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/902640880/

