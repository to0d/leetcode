#include <lt_help/lt.h>

class Solution {
public:
    int rob(TreeNode* root) {
        int chooseValue, noChooseValue;
        robTree(root, chooseValue, noChooseValue);
        return std::max( chooseValue, noChooseValue);
    }
    
    void robTree(TreeNode* node, int& chooseValue, int& notChooseValue) {
        if( node == NULL )
        {   chooseValue = 0, notChooseValue = 0;
            return;
        }
        int leftChooseValue, leftNotChooseValue, rightChooseValue, rightNotChooseValue;
        robTree(node->left , leftChooseValue , leftNotChooseValue);
        robTree(node->right, rightChooseValue, rightNotChooseValue);

        chooseValue    = leftNotChooseValue + rightNotChooseValue + node->val;
        notChooseValue = std::max(leftChooseValue   , leftNotChooseValue) 
                       + std::max(rightChooseValue  , rightNotChooseValue);
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);   
    int r = Solution().rob(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{3,4,5,1,3,#,1}"));
}

// Result 
//
// 2022-11-14: Runtime 28ms 31.29% Memory 22.3MB 78.18%, https://leetcode.com/problems/house-robber-iii/submissions/843009396/
// 2023-02-22: Runtime 19ms 62.23% Memory 22.1MB 99.52%, https://leetcode.com/problems/house-robber-iii/submissions/902750501/
// 2023-03-12: Runtime 12ms 83.98% Memory 22.2MB 92.88%, https://leetcode.com/problems/house-robber-iii/submissions/913528704/


