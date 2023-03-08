#include <lt_help/lt.h>

class Solution {
public:
    int findTilt(TreeNode* root) {
        m_tilt = 0;
        _findTilt(root);
        return m_tilt;
    }
    
    int _findTilt(TreeNode* node) {
        if( node == NULL )
            return 0;
        int leftSum  = _findTilt(node->left);
        int rightSum = _findTilt(node->right);
        m_tilt += std::abs(leftSum-rightSum);
        return node->val + leftSum + rightSum;
    }
    
    int m_tilt;
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().findTilt(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,2,3}"));
}

// Result 
//
// 2022-11-23: Runtime 23ms 52.1% Memory 24.1MB 5.46%, https://leetcode.com/problems/binary-tree-tilt/submissions/848452331/
// 2023-03-09: Runtime 12ms 95.7% Memory 23.7MB 84.59%, https://leetcode.com/problems/binary-tree-tilt/submissions/911561853/



