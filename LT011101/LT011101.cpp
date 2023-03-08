#include <lt_help/lt.h>

class Solution {
public:
    int minDepth(TreeNode* root) {
        if( root == NULL)
            return 0;
        return _minDepth(root, -1);
    }

    int _minDepth(TreeNode* node, int maxSearchDeep){ // opt: maxSearchDeep, refer LT011001.cpp
        if( maxSearchDeep == 0 )
            return -1;
        
        int leftHeight = 0, rightHeight = 0;
        if( node->left != NULL )       
            leftHeight = _minDepth(node->left, maxSearchDeep-1);

        if( maxSearchDeep < 0 && leftHeight > 0)
            maxSearchDeep = leftHeight+2;

        if( node->right != NULL )       
            rightHeight = _minDepth(node->right, maxSearchDeep-1);

        if( leftHeight <=0 )
            return rightHeight + 1;
        
        if( rightHeight <= 0 )
            return leftHeight + 1;

        return std::min(leftHeight, rightHeight) + 1;
    }
};


    
void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().minDepth(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{3,9,20,null,null,15,7}"));
}

// Result 
//
// 2022-11-23: Runtime 437ms 12.40% Memory 144.6MB 80.90%, https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/848475633/
// 2023-02-22: Runtime 353ms 10.45% Memory 144.6MB 81.63%, https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/902625072/
// 2023-03-08: Runtime 279ms 69.34% Memory 144.6MB 81.14%, https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/911345687/



