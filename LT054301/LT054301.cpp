#include <lt_help/lt.h>

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        search(root, maxDiameter);
        return maxDiameter;
    }

    int search(TreeNode* node, int& maxDiameter) {
        if( node == NULL )
            return 0;
        int ld = search(node->left, maxDiameter);
        int rd = search(node->right, maxDiameter);
        maxDiameter = std::max(maxDiameter, ld+rd);
        return std::max(ld, rd)+1;
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
// 2023-03-09: Runtime 7ms 90.99% Memory 20.7MB 12.31%, https://leetcode.com/problems/diameter-of-binary-tree/submissions/911555992/
// 2023-03-11: Runtime 11ms 69.23% Memory 20.4MB 30.35%, https://leetcode.com/problems/diameter-of-binary-tree/submissions/913239198/
// 2023-03-17: Runtime 13ms 52.51% Memory 20.3MB 30.50%, https://leetcode.com/problems/diameter-of-binary-tree/submissions/916682262/



