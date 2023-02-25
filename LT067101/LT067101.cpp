#include <lt_help/lt.h>

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if( root == NULL || root->left == NULL)
            return -1;
        return _findSecondMinimumValue(root, root->val);
    }
    
    int _findSecondMinimumValue(TreeNode* node, int _min) {
        if( node->val > _min)
            return node->val;
        if( node->left == NULL) 
            return -1;
        int m1 = _findSecondMinimumValue(node->left, _min);  
        int m2 = _findSecondMinimumValue(node->right, _min);
        if( m1 == -1 )
            return m2;
        if( m2 == -1 )
            return m1;
        return std::min(m1, m2);        
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().findSecondMinimumValue(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{2,2,5,null,null,5,7}"));
}

// Result 
//
// 2023-01-10: Runtime 4ms 35.77% Memory 7.1MB 77.50%, https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/submissions/875494473/
// 2023-02-25: Runtime 0ms 100% Memory 7MB 97.83%, https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/submissions/904432580/


