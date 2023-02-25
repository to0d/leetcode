#include <lt_help/lt.h>

class Solution {
public:
    int rob(TreeNode* root) {
        if( root == NULL )
            return 0;

        int chooseValue = 0, noChooseValue = 0;
        robTree(root, chooseValue, noChooseValue);
        return std::max( chooseValue, noChooseValue);
    }
    
    void robTree(TreeNode* node, int& chooseValue, int& noChooseValue) {
        int ccount = 0;
        TreeNode* cnode = NULL;
        if( node->left != NULL ) {
            ccount++;
            cnode = node->left;
        }

        if( node->right != NULL ) {
            ccount++;
            cnode = node->right;
        }
        
        if( ccount == 0 )
        {   chooseValue = node->val;
            noChooseValue = 0;
            return;
        }
        
        if( ccount == 1 )
        {   int childChooseValue = 0, childNoChooseValue = 0;
            robTree( cnode, childChooseValue, childNoChooseValue);
            chooseValue = childNoChooseValue + node->val;
            noChooseValue = std::max(childChooseValue, childNoChooseValue);
            return;
        }
        
        int leftChooseValue = 0, leftNoChooseValue = 0, rightChooseValue = 0, rightNoChooseValue = 0;
        robTree( node->left, leftChooseValue, leftNoChooseValue); 
        robTree( node->right, rightChooseValue, rightNoChooseValue); 

        chooseValue = leftNoChooseValue + rightNoChooseValue + node->val;
        noChooseValue = std::max(leftChooseValue, leftNoChooseValue) 
                      + std::max(rightChooseValue, rightNoChooseValue);
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


