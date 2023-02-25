#include <lt_help/lt.h>



class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        _goodNodes(root, INT_MIN, count);
        return count;
    }
    
    void _goodNodes(TreeNode* node, int maxVal, int& count) {
        if( node == NULL )
            return;
        if( node->val >= maxVal )
        {   count++;
            maxVal = node->val;
        }
        _goodNodes(node->left, maxVal, count);
        _goodNodes(node->right, maxVal, count);
    }
};


void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().goodNodes(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{3,1,4,3,null,1,5}"));
}

// Result 
//
// 2023-01-14: Runtime 139ms 77.42% Memory 86.4MB 61.55%, https://leetcode.com/problems/count-good-nodes-in-binary-tree/submissions/877791913/


