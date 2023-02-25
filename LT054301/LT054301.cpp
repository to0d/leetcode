#include <lt_help/lt.h>

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int deep = 0, diameter = 0;
        search(root, &deep, &diameter);
        return diameter;
    }

    void search(TreeNode* node, int* deep, int* maxDiameter) {
        if( node == NULL )
        {   *deep = 0;
            return;
        }

        int ld, rd, md;
        search(node->left, &ld, maxDiameter);
        search(node->right, &rd, maxDiameter);
        
        md = ld+rd;
        if( md > *maxDiameter )
            *maxDiameter = md;

        *deep = ld > rd ? ld+1: rd+1;
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().diameterOfBinaryTree(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,2,3,4,5}"));
}

// Result 
//
// 2022-11-23: Runtime 19ms 29.38% Memory 20.5MB 14.49%, https://leetcode.com/problems/diameter-of-binary-tree/submissions/848453972/
// 2023-02-24: Runtime 9ms 75.41% Memory 20.7MB 12.53%, https://leetcode.com/problems/diameter-of-binary-tree/submissions/904151458/



