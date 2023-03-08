#include <lt_help/lt.h>

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        m_minDiff = INT_MAX, m_lastVal = INT_MIN + root->val + 1;
        _inorderTraversal(root);
        return m_minDiff;
    }
    
    void _inorderTraversal(TreeNode* node) {
        if(node == NULL)
            return;
        
        _inorderTraversal(node->left);

        int diff = node->val - m_lastVal;
        m_minDiff = std::min(m_minDiff, diff);
        m_lastVal = node->val;

        _inorderTraversal(node->right);
    }
    
    int m_lastVal;
    int m_minDiff;
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().getMinimumDifference(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{4,2,6,1,3}"));
}

// Result 
//
// 2022-11-23: Runtime 46ms 9.29% Memory 25.1MB 97.5%, https://leetcode.com/problems/minimum-absolute-difference-in-bst/submissions/848455519/
// 2023-02-24: Runtime 11ms 96.67% Memory 25.3MB 59.5%, https://leetcode.com/problems/minimum-absolute-difference-in-bst/submissions/904150665/
// 2023-03-09: Runtime 16ms 77.66% Memory 25.2MB 85.55%, https://leetcode.com/problems/minimum-absolute-difference-in-bst/submissions/911553456/


